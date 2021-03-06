//============================================================================//
// File:          compiler.h                                                  //
// Description:   Compiler independent data types for embedded solutions      //
// Author:        Uwe Koppe                                                   //
// e-mail:        koppe@microcontrol.net                                      //
//                                                                            //
// Copyright (C) MicroControl GmbH & Co. KG                                   //
// 53844 Troisdorf - Germany                                                  //
// www.microcontrol.net                                                       //
//                                                                            //
//----------------------------------------------------------------------------//
// Redistribution and use in source and binary forms, with or without         //
// modification, are permitted provided that the following conditions         //
// are met:                                                                   //
// 1. Redistributions of source code must retain the above copyright          //
//    notice, this list of conditions, the following disclaimer and           //
//    the referenced file 'COPYING'.                                          //
// 2. Redistributions in binary form must reproduce the above copyright       //
//    notice, this list of conditions and the following disclaimer in the     //
//    documentation and/or other materials provided with the distribution.    //
// 3. Neither the name of MicroControl nor the names of its contributors      //
//    may be used to endorse or promote products derived from this software   //
//    without specific prior written permission.                              //
//                                                                            //
// Provided that this notice is retained in full, this software may be        //
// distributed under the terms of the GNU Lesser General Public License       //
// ("LGPL") version 3 as distributed in the 'COPYING' file.                   //
//                                                                            //
//----------------------------------------------------------------------------//
//                                                                            //
// Date        History                                                        //
// ----------  -------------------------------------------------------------- //
// 04.12.1998  Initial version                                                //
// 29.04.1999  New data type definitions, Machine dependent definitions       //
// 07.09.2000  New symbol for const/code                                      //
// 18.12.2008  Use 'typedef' instead of '#define', introduce MC_COMPILER      //
//                                                                            //
//============================================================================//

#ifndef  COMPILER_H_
#define  COMPILER_H_


//------------------------------------------------------------------------------
// SVN  $Date: 2014-10-15 13:00:39 +0200 (Mi, 15. Okt 2014) $
// SVN  $Rev: 6273 $ --- $Author: tiderko $
//------------------------------------------------------------------------------



//-----------------------------------------------------------------------------
/*!
** \file    compiler.h
** \brief   Definition of compiler independent data types
**
** Due to different implementations of data types in the world of C compilers,
** the following data types are used:
** \li \c bool_t   :   Boolean value, True or False
** \li \c uint8_t  :   1 Byte value, value range 0 .. 2<sup>8</sup> - 1
** (0 .. 255)
** \li \c int8_t   :   1 Byte value, value range -2<sup>7</sup> ..
** 2<sup>7</sup> - 1 (-128 .. 127)
** \li \c uint16_t :   2 Byte value, value range 0 .. 2<sup>16</sup> - 1
** (0 .. 65535)
** \li \c int16_t  :   2 Byte value, value range -2<sup>15</sup> ..
** 2<sup>15</sup> - 1
** \li \c uint32_t :   4 Byte value, value range 0 .. 2<sup>32</sup> - 1
** \li \c int32_t  :   4 Byte value, value range -2<sup>31</sup> ..
** 2<sup>31</sup> - 1
** \li \c uint64_t :   8 Byte value, value range 0 .. 2<sup>64</sup> - 1
** \li \c int64_t  :   8 Byte value, value range -2<sup>63</sup> ..
** 2<sup>63</sup> - 1
**
** The compiler type/version is evaluated via its internal predefined
** symbols. If your compiler is not (yet) supported, you will get the
** following error message upon compilation:
** <p>
** <i>Data types are not defined! Please check compiler definition.</i>
** <p>
** <p>
** The following C compilers are supported by this file:
** \li Fujitsu C compiler for 16LX/16FX series (Softune)
** \li GNU C for Apple Mac-OS (Darwin)
** \li GNU C for ARM controller
** \li GNU C for Atmel AVR controller
** \li GNU C for Atmel AVR32 controller
** \li GNU C for ColdFire controller
** \li GNU C for Linux
** \li GNU C for PowerPC CPU (VxWorks)
** \li Hi-Tech PICC18 for Microchip PIC18 controller
** \li IAR C compiler for ARM controller
** \li Imagecraft C compiler for Atmel AVR controller
** \li Keil C compiler for 8051 controller
** \li Keil C compiler for 80C16x controller
** \li Keil C compiler for ARM controller
** \li Metrowerks C compiler
** \li Microchip C30 compiler for PIC24 and dsPIC
** \li Microsoft Visual C/C++ compiler
** \li National Instruments CVI compiler
** \li Renesas NC30 compiler for R8C and M16C controller
** \li TI Code Composer for C2000 DSPs
**
** <p>
**
** \def CPP_CONST
** The symbol \c CPP_CONST defines the expression for keeping data
** in the flash area.
**
** \def CPP_DATA_SIZE
** The symbol \c CPP_DATA_SIZE defines the largest supported data size
** (in bits) of the compiler. Typical values are 32 or 64. The data
** types \c uint64_t and \c int64_t are <b>not supported</b> if
** \c CPP_DATA_SIZE is 32.
**
** \def CPP_INLINE
** The symbol \c CPP_INLINE is used to declare a function as \c inline.
**
** \def CPP_PACK
** The symbol \c CPP_PACK is used to pack data structures.
**
** \def CPP_PARM_UNUSED
** The macro \c CPP_PARM_UNUSED is used to specify function parameters which
** are currently not used.
**
** \typedef Status_tv
** \brief   Data type for status value
**
** The #Status_tv typedef defines the data type for status values,
** typically used as return values. In order to keep the overhead
** small for different target platforms the data type can be adjusted.
**
**
*/

//-------------------------------------------------------------------
/*!
** \def MC_FALSE
*/
#ifndef  MC_FALSE
#define  MC_FALSE  0
#endif

/*!
** \def MC_TRUE
*/
#ifndef  MC_TRUE
#define  MC_TRUE   1
#endif


/*----------------------------------------------------------------------------*/
/* File specific splint configuration:                                        */
/* Do not report ISO reserved names (deprecated data types)                   */
/*@ -isoreserved                                                             @*/
/*----------------------------------------------------------------------------*/

#if defined(__LCLINT__)
#define  /*@notfunction@*/CPP_PARM_UNUSED(x)   /*@unused@*/x
#endif


//----------------------------------------------------------------------------//
// Target Machine / Compiler dependent definitions                            //
//                                                                            //
//----------------------------------------------------------------------------//



//--------------------------------------------------------------------
// Fujitsu C Compiler for 16LX/16FX series
//
#ifdef __COMPILER_FCC907__

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  short                Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// Deprecated data type definitions
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: __COMPILER_FCC907S__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// GNU C for Apple Mac-OS
//
#ifdef __GNUC__
#ifdef __APPLE__

#include <stdint.h>           // data types uint8_t ... uint64_t

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           __inline
#define  CPP_PACK             __attribute__ ((packed))
#ifndef  CPP_PARM_UNUSED
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))
#endif

typedef  int32_t              Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// Deprecated data type definitions
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;
typedef  uint64_t             _U64;
typedef  int64_t              _S64;

#endif
#endif
// End of definition: __GNUC__ && __APPLE__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// GNU C for ARM controller
//
#ifdef __GNUC__
#ifdef __arm__

#include <stdint.h>           // data types uint8_t ... uint64_t

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           __inline
#define  CPP_PACK             __attribute__ ((packed))
#ifndef  CPP_PARM_UNUSED
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))
#endif
#define  CPP_NULL             0
/*!
** 1: Big endian
** 0: Little endian
*/
#define  CPP_BIG_ENDIAN       0

typedef  int32_t              Status_tv;

typedef  _Bool                bool_t;

//--------------------------------------------------------------
// Deprecated data type definitions
//
typedef  _Bool                _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;
typedef  uint64_t             _U64;
typedef  int64_t              _S64;

#endif
#endif
// End of definition: __GNUC__ && __arm__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// GNU C for Atmel AVR controller
//
#ifdef __GNUC__
#ifdef __AVR__

#include <stdint.h>           // data types uint8_t ... uint32_t, user space

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE           inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))

typedef  int8_t               Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;

#endif
#endif
// End of definition: __GNUC__ && __AVR__
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// GNU C for Atmel AVR32 controller
//
#ifdef __GNUC__
#ifdef __AVR32__

#include <stdint.h>           // data types uint8_t ... uint32_t, user space

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE           inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))

typedef  int8_t               Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;

#endif
#endif
// End of definition: __GNUC__ && __AVR32__
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// GNU C for ColdFire controller
//
#ifdef __GNUC__
#ifdef __mc68000__

#include <stdint.h>           // data types uint8_t ... uint64_t

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))

typedef  int8_t               Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;
typedef  uint64_t             _U64;
typedef  int64_t              _S64;

#endif
#endif
// End of definition: __GNUC__ && __mc68000__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
//  GNU C for Linux
//
#ifdef __GNUC__
#ifdef __linux__

#ifdef __KERNEL__
#include <linux/types.h>   // data types uint8_t ... uint32_t, kernel space
#else
#include <stdint.h>        // data types uint8_t ... uint32_t, user space
#endif

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           inline
#define  CPP_PACK
#ifndef  CPP_PARM_UNUSED
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))
#endif
typedef  int32_t              Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;
typedef  uint64_t             _U64;
typedef  int64_t              _S64;
#endif
#endif
// End of definition: __GNUC__ && __linux__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
//  GNU C for PowerPC CPU (VxWorks)
//
#ifdef __GNUC__
#ifdef _ARCH_PPC
#ifdef __vxworks

#include <types/VxTypes.h>

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   UNUSED_ ## x __attribute__((unused))

typedef  int32_t              Status_tv;

typedef  _Bool                bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  signed short         int16_t;
typedef  unsigned long        uint32_t;
typedef  signed long          int32_t;
typedef  unsigned long long   uint64_t;
typedef  signed   long long   int64_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  _Bool                _BIT;
typedef  unsigned char        _U08;
typedef  signed   char        _S08;
typedef  unsigned short       _U16;
typedef  signed   short       _S16;
typedef  unsigned long        _U32;
typedef  signed   long        _S32;
typedef  unsigned long long   _U64;
typedef  signed   long long   _S64;

#endif
#endif
#endif
// End of definition: __GNUC__ && _ARCH_PPC && __vxworks
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Hi-Tech C for Microchip PIC18 controller (PICC18)
//
#ifdef HI_TECH_C

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  int8_t               Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: HI_TECH_C
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// IAR C compiler for ARM controller
//
#ifdef __ICCARM__

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

#include <stdint.h>

typedef  int32_t              Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  uint8_t              _BIT;
typedef  uint8_t              _U08;
typedef  int8_t               _S08;
typedef  uint16_t             _U16;
typedef  int16_t              _S16;
typedef  uint32_t             _U32;
typedef  int32_t              _S32;

#endif
// End of definition: __ICCARM__
//--------------------------------------------------------------------



//-------------------------------------------------------------------
// Imagecraft C compiler for Atmel AVR controller
//
#ifdef _AVR

#define  CPP_CONST
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE           __inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  int32_t              Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: _AVR
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Keil C compiler for 8051 controller
//
#ifdef __C51__

#include <stdint.h>
#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  signed char          Status_tv;

typedef  unsigned char        bool_t;
//typedef  unsigned char        uint8_t;
//typedef  signed char          int8_t;
//typedef  unsigned short       uint16_t;
//typedef  short                int16_t;
//typedef  unsigned long        uint32_t;
//typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: __C51__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Keil C compiler for 80C16x controller
//
#ifdef __C166__

#define  CPP_CONST
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  signed short         Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: __C166__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Keil C compiler for ARM controller
//
#ifdef __arm

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE           __inline
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

#include <stdint.h>

typedef  int32_t              Status_tv;

//--------------------------------------------------------------
// The data types uint8_t, int8_t, uint16_t, int16_t,
// uint32_t, and int32_t are covered by <stdint.h>.
//
typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: __arm
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Metrowerks C compiler
//
#ifdef __MWERKS__

#define  CPP_CONST
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x


typedef  unsigned char        _BIT;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

typedef  int32_t              Status_tv;

typedef  uint8_t              bool_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: __MWERKS__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Microchip C30 compiler for PIC24 and dsPIC
//
#ifdef __C30
#ifdef __PIC24E__

#define  CPP_CONST
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   __attribute__((unused)) x

typedef  short                Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;
typedef  unsigned long long   uint64_t;
typedef  long long            int64_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;
typedef  unsigned long long   _U64;
typedef  long long            _S64;

#endif
#endif
// End of definition: __C30 && __PIC24E__
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// Microchip XC32 compiler for PIC32MX
//
#ifdef __XC32

#define  CPP_CONST
#define  CPP_DATA_SIZE        64
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   __attribute__((unused)) x

typedef  short                Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;
typedef  unsigned long long   uint64_t;
typedef  long long            int64_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;
typedef  unsigned long long   _U64;
typedef  long long            _S64;

#endif
// End of definition: __XC32 && __PIC32MX__
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// Microsoft Visual C/C++ compiler
//
#ifdef _MSC_VER

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  int32_t              Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: _MSC_VER
//-------------------------------------------------------------------



//--------------------------------------------------------------------
// National Instruments CVI
//
#ifdef _CVI_

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  int32_t              Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition: _CVI_
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Renesas NC30 compiler for R8C and M16C controller
//
#ifdef NC30

#define  CPP_CONST
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  short                Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition:  NC30
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// TI Code Composer for C2000 DSPs
//
#ifdef __TMS320C2000__

#define  CPP_CONST            const
#define  CPP_DATA_SIZE        32
#define  CPP_INLINE
#define  CPP_PACK
#define  CPP_PARM_UNUSED(x)   x

typedef  short                Status_tv;

typedef  unsigned char        bool_t;
typedef  unsigned char        uint8_t;
typedef  signed char          int8_t;
typedef  unsigned short       uint16_t;
typedef  short                int16_t;
typedef  unsigned long        uint32_t;
typedef  long                 int32_t;

//--------------------------------------------------------------
// deprecated list of data types
//
typedef  unsigned char        _BIT;
typedef  unsigned char        _U08;
typedef  signed char          _S08;
typedef  unsigned short       _U16;
typedef  short                _S16;
typedef  unsigned long        _U32;
typedef  long                 _S32;

#endif
// End of definition:  __TMS320C2000__
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// Test is used compiler has been recognised by checking the
// symbol CPP_DATA_SIZE.
//
#ifndef  CPP_DATA_SIZE
#error   Data types are not defined! Please check compiler definition.
#endif


#endif      // COMPILER_H_
