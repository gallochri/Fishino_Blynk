/************************************************************************
This is a library to handling capacitive multitouch sensors using FT5x06.

Simplified version, handles JUST one touch, but consistenttly

Created by Massimo Del Fedele - 11 Octobre 2015
*************************************************************************/
#ifndef _FT5x06_H
#define _FT5x06_H

/* FT5206 definitions */
#define FT5206_I2C_ADDRESS 0x38

// there are more registers, but this is enought to get all 5 touch coordinates.
#define FT5206_NUMBER_OF_REGISTERS 31     

#define FT5206_NUMBER_OF_TOTAL_REGISTERS 0xFE

#define FT5206_DEVICE_MODE 0x00

#define FT5206_GEST_ID 0x01
#define FT5206_GEST_ID_MOVE_UP     0x10
#define FT5206_GEST_ID_MOVE_LEFT   0x14
#define FT5206_GEST_ID_MOVE_DOWN   0x18
#define FT5206_GEST_ID_MOVE_RIGHT  0x1c
#define FT5206_GEST_ID_ZOOM_IN     0x48
#define FT5206_GEST_ID_ZOOM_OUT    0x49
#define FT5206_GEST_ID_NO_GESTURE  0x00

#define FT5206_TD_STATUS 0x02

#define FT5206_TOUCH1_XH 0x03
#define FT5206_TOUCH1_XL 0x04
#define FT5206_TOUCH1_YH 0x05
#define FT5206_TOUCH1_YL 0x06

#define FT5206_TOUCH2_XH 0x09
#define FT5206_TOUCH2_XL 0x0a
#define FT5206_TOUCH2_YH 0x0b
#define FT5206_TOUCH2_YL 0x0c

#define FT5206_TOUCH3_XH 0x0f
#define FT5206_TOUCH3_XL 0x10
#define FT5206_TOUCH3_YH 0x11
#define FT5206_TOUCH3_YL 0x12

#define FT5206_TOUCH4_XH 0x15
#define FT5206_TOUCH4_XL 0x16
#define FT5206_TOUCH4_YH 0x17
#define FT5206_TOUCH4_YL 0x18

#define FT5206_TOUCH5_XH 0x1b
#define FT5206_TOUCH5_XL 0x1c
#define FT5206_TOUCH5_YH 0x1d
#define FT5206_TOUCH5_YL 0x1e

#define FS5206_TOUCH_LIB_VERSION_H 0xa1
#define FS5206_TOUCH_LIB_VERSION_L 0xa2

class FT5x06
{
	private:
		uint8_t _ctpInt;

		uint16_t x, y;

	public:
		// constructor
		// parameter is arduino's interrupt pin
		FT5x06(uint8_t CTP_INT);
		
		// get last touch position
		void getTouchPosition(uint16_t &x, uint16_t &y);

		// check if it was touched since last call
		bool touched(void);
		
		// initialize the module
		// beware, Wire MUST be initialized BEFORE
		void init(void);
};

#endif