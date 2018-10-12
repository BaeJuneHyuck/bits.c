/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 *   PNU CSE,  BaeJuneHyuck, 201424465
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int notX = ~x;
  int notY = ~y;
  int XandY = ~(notX | notY);
  return XandY;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int byteMovedX = (x>>(n<<3));
  return  byteMovedX & 0xff;  
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask = ~(((1 << 31 ) >> n) << 1);
  return (x>>n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  
  // Divide and conquer algorithm of <Hacker's delight> 
  // add all adjacent bits. save result each 2-bit field.
  // again, add all adjacent 2bits. save result each 4-bit field.
  // once again, add all adjacent 4bits. save result  each 8-bit field.
  // now we can count bit by shift and sum four fields.
  int mask1 = (0x55<<24)+(0x55<<16)+(0x55<<8)+0x55;
  int mask2 = (0x33<<24)+(0x33<<16)+(0x33<<8)+0x33;
  int mask3 = (0x0f<<24)+(0x0f<<16)+(0x0f<<8)+0x0f;
 
  int s1 = x + ~((x>>1)& mask1) +1 ;
  int s2 = (s1 & mask2) + ((s1>>2)& mask2);
  int s3 = (s2+(s2>>4)&mask3);
  int count = ((s3<<24)+(s3<<16)+(s3<<8)+s3)>>24; 
  return count; 
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return ((x | (~x+1))>>31)+1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift = 33 + ~n;
  int signExtendedX = (x << shift)>>shift;
  return !(x ^ signExtendedX);
}
/* 	s.Push(1);
	s.Push(2);

 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int sign = x >> 31;
  int mask = (1<<n) + ~0; //used when x is negative
  return ( x + (sign & mask)) >> n;
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x +1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  //int isZero = !(x|(~x+1));
  int isZero = !x;
  // !( if 0 and negative then 1 else 0 );
  return !(( isZero| (x>>31) ) & 1);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signX = x>>31;
  int signY = y>>31;
  int signYsubX = (y+(~x+1))>>31;
  int signDiff = (!signX) ^(!signY);
  // case1 : x is neg, y is positive 
  int case1 = signDiff & signX;
  // case2 : y-x is pos, same sign 
  // if x >0 y>0 then x<y
  // if x<0 y<0 then x<y
  int case2 = !signDiff & !(signYsubX);
  return case1|case2;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90 
 *   Rating: 4
 */
int ilog2(int x) {
  // find the largest 1 
  int bitCount = 0;
  int right1filledX = x;
  int mask1 = (0x55<<24)+(0x55<<16)+(0x55<<8)+0x55;
  int mask2 = (0x33<<24)+(0x33<<16)+(0x33<<8)+0x33;
  int mask3 = (0x0f<<24)+(0x0f<<16)+(0x0f<<8)+0x0f;
  int s1=0;
  // step 1 make right bits of the largest 1 bit to all 1 
  right1filledX = x|(x>>1);
  right1filledX |= right1filledX>>2;
  right1filledX |= right1filledX>>4;
  right1filledX |= right1filledX>>8;
  right1filledX |= right1filledX>>16;
  
  //step2 bitcount
  //count the number of 1bits and -1. that is the position of  largest 1 bit
  s1 = right1filledX + ~((right1filledX>>1)& mask1) +1 ;
  s1 = (s1 & mask2) + ((s1>>2)& mask2);
  s1 = (s1+(s1>>4)&mask3);

  bitCount = ((s1<<24)+(s1<<16)+(s1<<8)+s1)>>24; 
  return bitCount+(~0);
  }
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int fracMask = 0x007FFFFF;
  int expMask = ((0xFF)<<23);
  // if NaN, (exp - 111111, frac != 0 )
  if (( (uf&expMask) == expMask) && (uf & fracMask))   {
  return uf;
 }else{
  return uf ^ (1<<31);
 }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int sign = x & 0x80000000;
  int nShift = 0;
  int exp = 0;
  int frac = 0;
  int absX = x;
  if (x==0) return 0;
  if (x==0x80000000) return 0xcf000000;
  if (x<0)
    absX = -x;
  // step1 . Normialize
  while ( (absX & 0x80000000)!=0x80000000 ) {
    nShift ++;
    absX = absX<<1;
  }  
  
  // step 2. Rounding :  to nearest even
 
  // case 2-1. overflow
  if ( absX >= 0xFFFFFF80 ){
    nShift--;
    absX=0;
  }	
  // case 2-2.  Half
  else if ( (absX & 0xFF) == 0x80 ){ 
    if (absX &0x100){
      absX = absX +0x100;
    }
  }
  // case 2-3. round up
  else if ( (absX & 0xFF) > 0x80 ){
      absX = absX +0x100;
  }
  // step 3. combine
  frac = (absX>>8)&0x7FFFFF;
  exp = 31-nShift+127;
  return sign | (exp<<23) | frac;
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int frac = 0x007FFFFF&uf ;
  int exp = ((0xFF)<<23)&uf;
  int sign = (uf >>31)<<31;
  // case Special (exp == 11..1)
  if ( uf ==0  | uf == 0x80000000 | exp == 0xFF800000 | exp == 0x7F800000){
    return uf;
  } else if ( exp > 0){ // case Normal
    return uf + (1<<23); //exp + 1	  
  }else{ // case denormal, exp == 0
    if ( frac >= 0x00400000){
       exp = exp + 0x0800000;
       frac = (frac << 1) & (0x007FFFFF);
       return sign+exp+frac; 
    }else{
      return sign+exp+(frac<<1); 
    }
  }
}
