/*
 * Sound device register definitions for the F256K
 */

#ifndef __SOUND_F256_H
#define __SOUND_F256_H

#include <stdint.h>

#define PSG_PORT        ((volatile __attribute__((far)) uint8_t *)0xffc02000) 	/* Control register for the SN76489 */
#define PSG_PORT_L      ((volatile __attribute__((far)) uint8_t *)0xffc02010) 	/* Control register for the SN76489 */
#define PSG_PORT_R      ((volatile __attribute__((far)) uint8_t *)0xffc02020) 	/* Control register for the SN76489 */

#define OPL3_PORT       ((volatile uint8_t *)0xffc06000)  						/* Access port for the OPL3 */

#define CODEC           ((volatile __attribute__((far)) uint16_t *)0xffc00200)	/* Data register for the CODEC */
#define CODEC_WR_CTRL	((volatile __attribute__((far)) uint8_t *)0xffc00202)	/* Data register for the CODEC */

/*
 * Internal SID
 */

struct s_sid_voice {
	uint16_t frequency;
	uint16_t pulse_width;
	uint8_t control;
	uint8_t attack_decay;
	uint8_t sustain_release;
};

struct s_sid {
	struct s_sid_voice v1;
	struct s_sid_voice v2;
	struct s_sid_voice v3;

	uint16_t filter_frequency;
	uint8_t resonance_filter;
	uint8_t mode_volume;
	
	uint8_t pot_x;
	uint8_t pot_y;
	uint8_t osc3;
	uint8_t env3;
};

#define SID_INT_N_V1_FREQ_LO  	((volatile __attribute__((far)) uint8_t *)0xffc04200)
#define SID_INT_L_V1_FREQ_LO  	((volatile __attribute__((far)) uint8_t *)0xffc04000)
#define SID_INT_R_V1_FREQ_LO  	((volatile __attribute__((far)) uint8_t *)0xffc04100)

#define SID_INT_N  				((volatile __attribute__((far)) struct s_sid *)0xffc04200)

#endif
