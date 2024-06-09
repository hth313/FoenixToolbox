#include <stdint.h>

#include "dma.h"
#include "dma_reg.h"
#include "vicky_general.h"

/**
 * @brief Check if an address is in the range of video RAM
 * 
 * @param address the address to check
 * @return short 0 if it is not in video RAM, 1 if it is in video RAM
 */
short is_vram(uint8_t * address) {
	if ((uint32_t)address >= (uint32_t)vram_base) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * @brief Wait while the VDMA engine is busy
 * 
 */
void vdma_wait() {
	while ((*VDMA_STAT & VDMA_STAT_TFR_BUSY) != 0) ;
}

/**
 * @brief Fill video memory using a linear VDMA operation
 * 
 * @param dest the address of memory to fill (must be in video RAM)
 * @param value the value to put into memory
 * @param count the number of bytes to fill
 */
void vdma_fill_linear(uint8_t * dest, uint8_t value, long count) {
	if (is_vram(dest)) {
		// We'll just ignore non-vram addresses

		// Make sure any previous transfer is complete
		vdma_wait();		

		*VDMA_CTRL = 0;

		// Set us up for a 1D fill
		*VDMA_CTRL = VDMA_CTRL_EN | VDMA_CTRL_FILL;

		// Set the fill value
		*VDMA_FILL_VALUE = value;

		// Set the destination address
		uint32_t dest_vram_address = (uint32_t)dest - (uint32_t)vram_base;
		VDMA_DST_ADDR[0] = (uint8_t)(dest_vram_address & 0xff);
		VDMA_DST_ADDR[1] = (uint8_t)((dest_vram_address >> 8) & 0xff);
		VDMA_DST_ADDR[2] = (uint8_t)((dest_vram_address >> 16) & 0xff);
		
		// Set the count
		VDMA_SIZE[0] = (uint8_t)(count & 0xff);
		VDMA_SIZE[1] = (uint8_t)((count >> 8) & 0xff);
		VDMA_SIZE[2] = (uint8_t)((count >> 16) & 0xff);
		
		// Start the transfer
		*VDMA_CTRL = VDMA_CTRL_EN | VDMA_CTRL_FILL | VDMA_CTRL_TRF;

		// Wait for completion
		for (int i = 0; i < 10; i++) ;

		vdma_wait();

		// Turn off the VDMA engine
		*VDMA_CTRL = 0;
	}
}


/**
 * @brief Copy data to video memory using a linear VDMA operation
 * 
 * @param dest the address of memory to copy to (must be in video RAM)
 * @param src the address of memory to copy from (must be in system RAM)
 * @param count the number of bytes to fill
 */
void vdma_copy_linear(uint8_t * dest, uint8_t * src, long count) {
if (is_vram(dest)) {
		// We'll just ignore non-vram destinations

		// Make sure any previous transfer is complete
		vdma_wait();		

		*VDMA_CTRL = 0;
		*SDMA_CTRL = 0;

		uint32_t src_vram_address = (uint32_t)src;
		uint32_t dest_vram_address = (uint32_t)dest - (uint32_t)vram_base;

		// Set us up for a 1D copy that goes from SRAM to VRAM
		*VDMA_CTRL = VDMA_CTRL_EN | VDMA_CTRL_SRC_SRAM;
		*SDMA_CTRL = SDMA_CTRL_EN | 0x10;

		// Set the source address
		SDMA_SRC_ADDR[0] = (uint8_t)(src_vram_address & 0xff);
		SDMA_SRC_ADDR[1] = (uint8_t)((src_vram_address >> 8) & 0xff);
		SDMA_SRC_ADDR[2] = (uint8_t)((src_vram_address >> 16) & 0xff);
		SDMA_DST_ADDR[0] = 0;
		SDMA_DST_ADDR[1] = 0;
		SDMA_DST_ADDR[2] = 0;
		
		// Set the destination address
		VDMA_SRC_ADDR[0] = 0;
		VDMA_SRC_ADDR[1] = 0;
		VDMA_SRC_ADDR[2] = 0;
		VDMA_DST_ADDR[0] = (uint8_t)(dest_vram_address & 0xff);
		VDMA_DST_ADDR[1] = (uint8_t)((dest_vram_address >> 8) & 0xff);
		VDMA_DST_ADDR[2] = (uint8_t)((dest_vram_address >> 16) & 0xff);
		
		// Set the count
		VDMA_SIZE[0] = (uint8_t)(count & 0xff);
		VDMA_SIZE[1] = (uint8_t)((count >> 8) & 0xff);
		VDMA_SIZE[2] = (uint8_t)((count >> 16) & 0xff);
		SDMA_SIZE[0] = (uint8_t)(count & 0xff);
		SDMA_SIZE[1] = (uint8_t)((count >> 8) & 0xff);
		SDMA_SIZE[2] = (uint8_t)((count >> 16) & 0xff);
		
		// Start the transfer
		*VDMA_CTRL = VDMA_CTRL_EN | VDMA_CTRL_SRC_SRAM | VDMA_CTRL_TRF;
		*SDMA_CTRL = SDMA_CTRL_EN | 0x10 | SDMA_CTRL_TRF;

		// Wait for completion
		vdma_wait();

		// Turn off the DMA engine
		*VDMA_CTRL = 0;
		*SDMA_CTRL = 0;
	}
}