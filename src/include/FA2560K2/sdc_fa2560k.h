/*
 * Definitions for access to the SDC controller using the SPI interface
 */

#ifndef __SDC_FA2560K_H
#define __SDC_FA2560K_H

#include <stdint.h>

typedef struct s_sdc_spi {
	uint8_t ctrl;
	uint8_t rsrv_1;         // Leave a gap for the word alignment
	uint8_t data;
	uint8_t rsrv_2;         // Leave a gap for the word alignment
} t_sdc_spi, *p_sdc_spi;

#define SDx_CS				0x01		// 1 = Enable
#define SDx_SLOW 			0x02		// 1 = Slow 400Khz, 0 = 25Mhz
#define SDx_BUSY			0x80		// 1 = Busy

#define SD0_REG				((volatile __attribute__((far)) p_sdc_spi)0xffb08000)
#define SD1_REG				((volatile __attribute__((far)) p_sdc_spi)0xffb0a000)

#define SD0_STAT            (*(volatile __far uint8_t *)0xffb00000)
#define SD0_STAT_CD         0x40  // When 1 = No Card, 0 = Card is Present
#define SD0_STAT_WP         0x80  // When 0 = Writeable, 1 = Card is Protected

#endif
