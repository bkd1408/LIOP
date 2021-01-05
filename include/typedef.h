
#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

typedef unsigned long		DWORD;
typedef unsigned int		WORD;
typedef unsigned char		BYTE;
typedef signed long			SDWORD;
typedef signed int			SWORD;
typedef signed char			SBYTE;

#define bit_select(B, i)	((B >> i) & 1)
#define bit_set(B, i)		(B |= (1 << i))
#define bit_reset(B, i)		(B &= ~(1 << i))

#endif

