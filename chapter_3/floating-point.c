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
 *
 * Integer Conversion Rank
 *
 * An integer conversion rank is a standard rank ordering of integer types used
 * to determine a common type for computations. Every integer type has an
 * integer conversion rank that determines when and how conversions are
 * implicitly performed.
 *    The C Standard states that every integer type has an integer conversion
 * rank where the following applies:
 *
 * - No two signed integer types have the same rank, even if they have the same
 * representation.
 * - The rank of a signed integer type is greater than the rank of any signed
 * integer type with less precision.
 * - The rank of long long int is greater than the rank of long int, which is
 * greater than the rank of int, which is greater than the rank of short int,
 * which is greater than the rank of signed char.
 * - The rank of any unsigned integer type equals the rank of the corresponding
 * signed integer type, if any.
 * - The rank of char equals the rank of signed char and unsigned char.
 * - The rank of _Bool is less than rank of all other standard integer types.
 * - The rank of any enumerated type equals the rank of the compatible integer
 * type. Each enumerated type is compatible with char, a signed integer type, or
 * an unsigned integer type.
 * - The rank of any extended signed integer type relative to another extended
 * signed integer type with the same precision is implementation-defined but
 * still subject to the other rules for determining the integer conversion rank.
 *
 * Integer Promotions
 *
 * A small type s an integer with a lower conversion rank than int or unsigned
 * int. Integer promotion is the process of converting values of small types to
 * an int or unsigned int. Integer promotions allow you to use an expression of
 * a small type in any expression where an int or unsigned int may be used.
 *    Small integer types (char, short) get automatically converted to int or
 * unsigned int for before operations for two reasons:
 *
 *  1. Performance - CPUs work naturally in int size
 *  2. Overflow prevention - intermediate calculations have more room
 * This behaviour can always be overridden with an explicit cast.
 *
 * Usual Arithmetic Conversions
 *
 * The usual arithmetic conversions are rules for yielding a common type by
 * balancing both operands of a binary operator to a common type, or balancing
 * the second and third arguments of the conditional (? :) operator to a common
 * type.
 *    Balancing conversions changes one or both operands of different types to
 * the same type. Many operators that accept integer operands--including *, /,
 * %, +, -, <, >, <=, >=, ==, !=, &, ^, |, and ? :--perform conversions using
 * the usual arithmetic conversions. The usual arithmetic conversion first check
 * whether one of the operands in the balancing conversion is a floating-point
 * type. If so, it applies the following rules:
 *
 *  1. If one type of either operand is long double, the other operand is
 * converted to long double.
 *  2. Otherwise, if one type or either operand is double, the other operand is
 * converted to double.
 *  3. Otherwise, if the type of either operand is float, the other operand is
 * converted to float.
 *  4. Otherwise, the integer promotions are performed on both operands.
 *
 *    If one operand has the type double and the other operand has the type int,
 * for example, the operand of the type int is converted to an object of type
 * double. If one operand has the type float and the other operand has the type
 * double, the operand of type float is converted to an object of type double.
 *    If neither operand is a floating-point type, the following usual
 * arithmetic conversion rules are applied to the promoted integer operands:
 *
 *  1. If both operands have the same type, no further conversion is needed.
 *  2. Otherwise, if both operands have signed integer types or both have
 * unsigned integer types, the operand with the type that has the lesser integer
 * conversion rank is converted to the type of the operand with greater rank. If
 * one operand has the type int and the other operand has the type long, for
 * example, the operand of type int is converted to an object of type long.
 * 3. Otherwise, if the operand that has the unsigned integer type has a rank
 * greater than or equal to the rank of the other operand's type, then the
 * operand with the signed integer type is converted to the type of the operand
 * with the unsigned integer type. For example, if one operand has the type
 * signed int, and the other operand has the type unsigned int, the operand of
 * type signed int is converted to an object of type unsigned int.
 * 4. Otherwise, if the type of the operand with the signed integer type an
 * represent all of the values of the type of the operand with unsigned integer
 * type, then the operand with unsigned integer type is converted to the type of
 * the operand with signed integer type. For example, if one operand has the
 * type unsigned int and the other operand has the type signed long long, and
 * the signed long long type can represent all the values of the unsigned int
 * type, then the operand of type unsigned int is converted to an object of type
 * signed long long.
 * 5. Otherwise, both operands are converted to the unsigned integer type
 * corresponding to the type of the operand with signed integer type.
 *
 *    When in doubt, use type casts to explicitly force the conversion that you
 * intend. That said, try not to overuse explicit conversions because casts can
 * disable important diagnostics.
 *
 * An Example of Implicit Conversion
 *
 * The following example illustrates the use of integer conversion rank, integer
 * promotions, and the usual arithmetic conversions. This code compares the
 * signed char value c for equality with the unsigned int value ui.
 *
 *  unsigned int ui = UINT_MAX;
 *  signed char c = -1;
 *  if (c == ui) {
 *    puts("-1 equals 4,294,967,295");
 *  }
 *
 *     The variable c is of type signed char. Because signed char has a lower
 * integer conversion rank than int or unsigned int, the value stored in c is
 * promoted to an object of type signed int when used in the comparison. This is
 * accomplished by sign-extending the original value of 0xFF to 0xFFFFFFFFF.
 * Sign extension is used to convert a signed value to a larger-width object.
 * The sign bit is copied into each bit position of the expanded object. This
 * operation preserves the sign and magnitude when converting a value from a
 * smaller to a larger, signed integer type.
 *    Next, the usual arithmetic conversions are applied. Because the operands
 * to the equal (==) operator have different signedness and equal rank, the
 * operand with the signed integer type is converted to the type of the operand
 * with the unsigned integer type. The comparison is then performed as a 32-bit
 * unsigned operation. Because UINT_MAX has the same values as the promoted and
 * converted value of c, the comparison yields 1, and the code snipped prints
 * the following:
 *
 *  -1 equals 4,294,967,295
 */
#include <limits.h>
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

  unsigned int ui = UINT_MAX;
  signed char c = -1;
  if (c == ui)
    printf("-1 equals 4,294,967,295\n");
  return 0;
}
