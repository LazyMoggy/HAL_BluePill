/**
  ****************************************************************************
  * @file    errors.h
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Error code definitions
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

typedef uint8_t errors_t;

typedef enum
{
    ERR_NONE                  = 0,  /* No error */
    ERR_TIMEOUT               = 1,  /* Operation Timed Out */
    ERR_ABORT                 = 2,  /* Procedure aborted */
    ERR_QUIT                  = 3,  /* Procedure aborted by request */
    ERR_BUSY                  = 4,  /* Device is busy */
    ERR_DIV_BY_ZERO           = 5,  /* Division by zero occurred, or would have */
    ERR_INVALID_ARG           = 6,  /* Invalid argument */
    ERR_WRONG_ARG_COUNT       = 7,  /* Wrong number of arguments */
    ERR_OVERFLOW              = 8,  /* Overflow */
    ERR_VALUE_OUT_OF_RANGE    = 9,  /* Value outside valid range */
    ERR_INITIALISE_FAILED     = 10, /* Device or function initialisation failed */
    ERR_NOT_INITIALISED       = 11, /* Device or function not initialised */
    ERR_NOT_IMPLEMENTED       = 12, /* Device or function not implemented */
    ERR_OPERATION_FAILED      = 13, /* Operation failed */
    ERR_OPERATION_NOT_VALID   = 14, /* Operation not valid, e.g. write to RO register */
    ERR_OPERATION_NOT_ALLOWED = 15, /* Operation not allowed, e.g. access level too low */
    ERR_INVALID_DEVICE        = 16, /* Invalid device */
    ERR_CRC_FAIL              = 17, /* CRC error */
    ERR_READ_ONLY             = 18, /* Parameter is not writeable */
    ERR_WRITE_ONLY            = 19, /* Parameter is not readable */
    ERR_MTX_ACCESS            = 20, /* mutex access failed */
    ERR_DISABLED              = 21, /* Function disabled */
    ERR_UNKNOWN               = 255 /* Unknown error */
} ERROR_CODES;


// EOF ************************************************************************
