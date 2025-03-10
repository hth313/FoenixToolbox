
/**
 * Definitions of major constants
 */

#ifndef __CONSTANTS_H
#define __CONSTANTS_H

/*
 * Miscellaneous definitions
 */

#define FSYS_SECTOR_SZ  512     /* Size of a sector */
#define MAX_PATH_LEN    256     /* Maximum length of a file path */

/*
 * Definitions of special characters
 */

#define CHAR_ESC    '\x1B'  /* Escape character */
#define CHAR_TAB    '\t'    /* Vertical tab */
#define CHAR_CR     '\x0D'  /* Carriage return */
#define CHAR_NL     '\x0A'  /* Linefeed */
#define CHAR_BS     '\b'    /* Backspace */

/*
 * File access mode and open method flags
 */
#define	FSYS_READ			0x01
#define	FSYS_WRITE		    0x02
#define	FSYS_OPEN_EXISTING  0x00
#define	FSYS_CREATE_NEW		0x04
#define	FSYS_CREATE_ALWAYS	0x08
#define	FSYS_OPEN_ALWAYS	0x10
#define	FSYS_OPEN_APPEND	0x30

/*
 * File attribute bits for directory entry
 */
#define	FSYS_AM_RDO         0x01	/* Read only */
#define	FSYS_AM_HID         0x02	/* Hidden */
#define	FSYS_AM_SYS         0x04	/* System */
#define FSYS_AM_DIR         0x10	/* Directory */
#define FSYS_AM_ARC         0x20	/* Archive */

/*
 * Block devices
 */

#define BDEV_SD0 0
#define BDEV_SD1 1
#define BDEV_HD0 1
#define BDEV_FD0 2

/*
 * Channel devices 
 */

#define CDEV_CONSOLE 0
#define CDEV_EVID 1
#define CDEV_COM1 2
#define CDEV_COM2 3
#define CDEV_LPT 4
#define CDEV_MIDI 5
#define CDEV_FILE 6

/*
 * Block Device IOCRTRL commands
 */

#define IOCTRL_CTRL_SYNC			0	/* Complete pending write process (needed at FF_FS_READONLY == 0) */
#define IOCTRL_GET_SECTOR_COUNT		1	/* Get media size (needed at FF_USE_MKFS == 1) */
#define IOCTRL_GET_SECTOR_SIZE		2	/* Get sector size (needed at FF_MAX_SS != FF_MIN_SS) */
#define IOCTRL_GET_BLOCK_SIZE		3	/* Get erase block size (needed at FF_USE_MKFS == 1) */

#endif
