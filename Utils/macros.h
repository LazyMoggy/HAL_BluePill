/**
  ****************************************************************************
  * @file    macros.h
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Utility Macro Definitions
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#ifndef AWMACROS_H
#define AWMACROS_H

/* Atomic Bit Fn's */
#define SETBIT(x, bp, bv) (x = (bv) ? (x | (1u << bp)) : (x & (~(1u<<bp))))
#define GETBIT(x, bp) ((x & (1u << bp)) >> bp)

/* Multiple Bit Fn's */
#define SETBITS(x, bp, bm, bv) (x = ((x & ~(bm << bp)) | (bv << bp)))
#define GETBITS(x, bp, bm) ((x & (bm << bp)) >> bp)

#define ARYLEN(ary) (sizeof(ary) / sizeof(ary[0]))

#endif


// EOF ************************************************************************
