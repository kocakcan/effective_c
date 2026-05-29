/***
 * Floating-Point
 *
 * Floating-point is the most common representation for real numbers in
 * computers. Floating-point representation is a technique that uses scientific
 * notation to encode numbers with a base number and an exponent. For example,
 * the decimal number 123.456 can be represented as 1.23456x10^2 while the
 * binary number 0b10100.110 can be represented as 1.0100110x10^2.
 *    You can generate floating-point representations in several ways. The C
 * Standard doesn't require that implementation to use any specific model,
 * although it does require every implementation to support some model. To keep
 * things simple, we'll assume conformance to Annex F. You can test the values
 * of the __STDC_IEC_559__ or __STDC_IEC_60559_BFP__ macros in newer compilers
 * to determine whether the implementation conforms to Annex F.
 *
 * Floating-Point Types
 *
 * C has three floating-point types: float, double, and long double.
 *    The float type can be used for floating-point calculations in which the
 * result can be adequately represented as a single-precision result. The common
 * IEC 60559 float type encodes value using 1 sign bit, 8 exponent bits, and 23
 * significant bits.
 *    The double type provides greater precision but requires additional
 * storage. It encodes values using 1 sign bits, 11 exponent bits, and 52
 * significant bits.
 *    Larger types have greater precision but require more storage. Any value
 * that can be represented as a float can also be represented as a double, and
 * any value that can be represented as a double can be represented as a long
 * double.
 *
 * Sign, Exponent, and Significand
 *
 * As with integers, the sign bits represents whether the number is positive or
 * negative: 0 denotes a positive number, and 1 denotes a negative number.
 *    The exponent field needs to represent both positive and negative
 * exponents. To avoid sotring the exponent as a signed number, a bias is
 * implicitly added to the actual exponent to get the stored exponent. For the
 * float type, the bias is 127. Consequently, to express an exponent of 0, we
 * would store 127 in the exponent field. A stored value of 200 indicates an
 * exponent of 200 - 127, or 73. Exponents of -127 (where every exponent bit is
 * 0) and +128 (where every exponent bit is 1) are reserved for special numbers.
 * Similarly, the bias for double-precision numbers is 1023. This means that the
 * value stored will range from 0 to 255 for a float, and 0 to 2047 for a
 * double.
 *    The significand bits represent the precision bits of the number. For
 * example, if you were to represent the value 1.0100110 x 2^4 as a
 * floating-point value, the significand refers to the precision bits. 1.0100110
 * and the exponent refers to the power of 2, which is 4 in this example.
 *
 * Floating-Point Arithmetic
 *
 * Floating-point arithmetic is similar to, and used to model, the arithmetic of
 * real numbers. However, there are differences to consider. In particular,
 * unlike the arithmetic of real numbers, floating-point numbers are bounded in
 * magnitude and have finite precision. Addition and multiplication operations
 * are not associative, the distributive property doesn't hold, nor do many
 * other properties that are valid for real numbers.
 *    Floating-point types cannot represent all real numbers exactly, even when
 * they can be represented in a small number of decimal digits. For example,
 * common decimal constants such as 0.1 can't be represented exactly as binary
 * floating-point numbers. Floating-point types may lack the necessary precision
 * for various applications such as loop counters or performing financial
 * calculations.
 *
 * Floating-Point Values
 *
 * Ordinarily, all of the significand bits in a floating-point type express
 * significant figures, in addition to a leading 1, which is implied and
 * omitted, though still considered part of the value. As a special case, to
 * represent the value 0, the exponent and significand must be both 0; zeros are
 * signed (+0 and -0) according to the sign bit, so there are two floating-point
 * zero values: a positive one and a negative one.
 *
 * Floating-Point Constants
 *
 * A floating-point constant is a decimal or hexadecimal number that represents
 * a signed real number. You should use floating-point constants to represent
 * floating-point values that cannot be changed.
 *
 *  15.75
 *  1.575E1 // 15.75
 *  1573E-2 // 15.75
 *  -2.5E-3 // -0.0025
 *  25E-4   // 0.0025
 *    All floating-point constants have a type. The type is double is
 * unsuffixed, float if suffixed by the letter f or F, or long double if
 * suffixed by the letter l or L:
 *
 *  10.0  // type double
 *  10.0F // type float
 *  10.0L // type long double
 */
#include <stdio.h>
#define BUFSIZ 1024

static char buf[BUFSIZ];

int getline_(char *s, int lim) {
  int c, i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c, i++;
  if (c == '\n')
    *s++ = c, i++;
  *s = '\0';
  return i;
}

int main(void) {
  if (getline_(buf, BUFSIZ) > 0)
    printf("Buffer: %s", buf);
  return 0;
}
