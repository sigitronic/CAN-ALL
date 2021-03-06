/*
 * CRC.c
 *
 *  Created on: 01.04.2017
 *********************************************
 *    (c)2016-2020 SIGITRONIC SOFTWARE       *
 *                                           *
 *      Author: Matthias Siegenthaler        *
 *                                           *
 *        matthias@sigitronic.com            *
 *********************************************
 */

#include "CRC.h"
static const uint8_t xdata CRCTable[256] =
{
	0x00, 0x2f, 0x5e, 0x71, 0xbc, 0x93, 0xe2, 0xcd,  //line 00
	0x57, 0x78, 0x09, 0x26, 0xeb, 0xc4, 0xb5, 0x9a,  //line 01
	0xae, 0x81, 0xf0, 0xdf, 0x12, 0x3d, 0x4c, 0x63,  //line 02
	0xf9, 0xd6, 0xa7, 0x88, 0x45, 0x6a, 0x1b, 0x34,  //line 03
	0x73, 0x5c, 0x2d, 0x02, 0xcf, 0xe0, 0x91, 0xbe,  //line 04
	0x24, 0x0b, 0x7a, 0x55, 0x98, 0xb7, 0xc6, 0xe9,  //line 05
	0xdd, 0xf2, 0x83, 0xac, 0x61, 0x4e, 0x3f, 0x10,  //line 06
	0x8a, 0xa5, 0xd4, 0xfb, 0x36, 0x19, 0x68, 0x47,  //line 07
	0xe6, 0xc9, 0xb8, 0x97, 0x5a, 0x75, 0x04, 0x2b,  //line 08
	0xb1, 0x9e, 0xef, 0xc0, 0x0d, 0x22, 0x53, 0x7c,  //line 09
	0x48, 0x67, 0x16, 0x39, 0xf4, 0xdb, 0xaa, 0x85,  //line 10
	0x1f, 0x30, 0x41, 0x6e, 0xa3, 0x8c, 0xfd, 0xd2,  //line 11
	0x95, 0xba, 0xcb, 0xe4, 0x29, 0x06, 0x77, 0x58,  //line 12
	0xc2, 0xed, 0x9c, 0xb3, 0x7e, 0x51, 0x20, 0x0f,  //line 13
	0x3b, 0x14, 0x65, 0x4a, 0x87, 0xa8, 0xd9, 0xf6,  //line 14
	0x6c, 0x43, 0x32, 0x1d, 0xd0, 0xff, 0x8e, 0xa1,  //line 15
	0xe3, 0xcc, 0xbd, 0x92, 0x5f, 0x70, 0x01, 0x2e,  //line 16
	0xb4, 0x9b, 0xea, 0xc5, 0x08, 0x27, 0x56, 0x79,  //line 17
	0x4d, 0x62, 0x13, 0x3c, 0xf1, 0xde, 0xaf, 0x80,  //line 18
	0x1a, 0x35, 0x44, 0x6b, 0xa6, 0x89, 0xf8, 0xd7,  //line 19
	0x90, 0xbf, 0xce, 0xe1, 0x2c, 0x03, 0x72, 0x5d,  //line 20
	0xc7, 0xe8, 0x99, 0xb6, 0x7b, 0x54, 0x25, 0x0a,  //line 21
	0x3e, 0x11, 0x60, 0x4f, 0x82, 0xad, 0xdc, 0xf3,  //line 22
	0x69, 0x46, 0x37, 0x18, 0xd5, 0xfa, 0x8b, 0xa4,  //line 23
	0x05, 0x2a, 0x5b, 0x74, 0xb9, 0x96, 0xe7, 0xc8,  //line 24
	0x52, 0x7d, 0x0c, 0x23, 0xee, 0xc1, 0xb0, 0x9f,  //line 25
	0xab, 0x84, 0xf5, 0xda, 0x17, 0x38, 0x49, 0x66,  //line 26
	0xfc, 0xd3, 0xa2, 0x8d, 0x40, 0x6f, 0x1e, 0x31,  //line 27
	0x76, 0x59, 0x28, 0x07, 0xca, 0xe5, 0x94, 0xbb,  //line 28
	0x21, 0x0e, 0x7f, 0x50, 0x9d, 0xb2, 0xc3, 0xec,  //line 29
	0xd8, 0xf7, 0x86, 0xa9, 0x64, 0x4b, 0x3a, 0x15,  //line 30
	0x8f, 0xa0, 0xd1, 0xfe, 0x33, 0x1c, 0x6d, 0x42   //line 31
};

uint8_t calcCRC7(uint8_t Data, uint8_t crc)
        {
    	// stupid hack to maintain compatibility with old eMove definition
			return(CRCTable[crc ^ Data]>>1);
        }

uint8_t calcCRC8(uint8_t Data, uint8_t crc)
        {
			return(CRCTable[crc ^ Data]);
        }


uint16_t calcCRC16(uint8_t Data, uint16_t crc)
{
  crc  = (crc >> 8) | (crc << 8);
  crc ^= Data;
  crc ^= (crc & 0xff) >> 4;
  crc ^= (crc << 8) << 4;
  crc ^= ((crc & 0xff) << 4) << 1;
  return crc;
}

/*uint16_t calcCRC16Array(uint16_t Length, uint8_t *Data, uint16_t crc)
{
  while(Length--)
  {
    crc = calcCRC16(*Data++, crc);
  }
  return crc;
}
*/

uint16_t calcCRC16Array(uint16_t Length, uint8_t *Data, uint16_t crc)
{
  uint8_t sizeArray;

  for (sizeArray = 0; sizeArray < Length; sizeArray++)
  {
	  crc = calcCRC16( Data[sizeArray], crc);
  }
  return crc;
}




