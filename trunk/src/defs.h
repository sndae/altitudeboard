#ifndef DEFS_H_
#define DEFS_H_

#include <inttypes.h>

#define TRUE = 1
#define FALSE = 0

typedef uint8_t 	uint8;
typedef int8_t 		int8;
typedef uint16_t 	uint16;
typedef int16_t		int16;
typedef uint32_t	uint32;
typedef int32_t		int32;

#define MAX_UINT8	(255)
#define MAX_UINT16	(65535)
#define MAX_UINT32	(4294967295)

#define MIN_INT8	(-128)
#define MAX_INT8	(127)
#define MIN_INT16	(-32768)
#define MAX_INT16	(32767)
#define MIN_INT32	(-2147483648)
#define MAX_INT32	(2147483647)

// MIN/MAX/ABS macros
#define MIN(a,b)			((a<b)?(a):(b))
#define MAX(a,b)			((a>b)?(a):(b))
#define ABS(x)				((x>0)?(x):(-x))

// constants
#define PI		3.14159265359

#endif /* DEFS_H_ */
