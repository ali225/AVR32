/*
  Author:  Khaled Hossam
  Date:    8/25/2019
  Version: 1.0
*/


#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int  u16;
typedef unsigned long u32;
typedef signed char   s8;
typedef signed int    s16;
typedef signed long   s32;
typedef float         f32;
typedef double        f64;


/* State datatype */
typedef enum
{
  LOW,
  HIGH

}State_t;

/* State datatype */
typedef enum
{
  SUCCESS,
  ERROR

}stdReturnType_t;


#endif
