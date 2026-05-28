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
