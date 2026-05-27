/***
 * 					Integers
 *
 * Each integer type represents a finite range of integers. Signed integer types
 * repres ent values that can be negative, zero, or positive; unsigned integers
 * represent valu es that can be only zero or positive. The range that each type
 * of integer can repres ent depends on your implementation. The value of an
 * integer object is the ordinary mathematical value stored in the object. The
 * representation of a value for an integer object is the particular encodi ng
 * of the value in the bits of the objects's allocated storage.
 *
 * Padding and Precision
 *
 * All integer types except char, signed char, and unsigned char may contain
 * unused bit s, called padding, that allow implementation to accommodate
 * hardware quirks (such as skipping over a sign bit in the middle of a
 * multiple-word representation) or to opti mally align with a target
 * architecture. The number of bits used to represent a value of a given type,
 * excluding padding but including the align, is called width and is o ften
 * denoted by N. The precision is the number of bits used to represent value,
 * excl uding sign and padding bits.
 *
 * The <limits.h> Header File
 *
 * The <limits.h> header file provides the minimum and maximum representable
 * values for the various integer types. A representable value is one that can
 * be represented in t he number of bits available to an object of a particular
 * type. Values that cannot be represented will be diagnosed by the compiler or
 * converted to a representable but di fferent (incorrect) value. Compiler
 * writers provide the correct minimum, maximum, an d width values for their
 * implementations. To write portable code, you should use the se constants,
 * rather than integer literals such as +214783647 that represent a speci fic
 * limit and may change when porting to a different implementation. The C
 * Standard imposes only three constraints on integer sizes. First, storage for
 * every data type occupies an integral number of adjacent unsigned char objects
 * ( which may include padding). Second, each integer type has to support the
 * minimum ran ges, allowing you to depend on a portalbe range of values across
 * any implementation. Third, smaller types cannot be wider than larger types.
 * So, for example, USHRT_MAX c annot be greater than UINT_MAX, but they can be
 * the same width.
 *
 * Declaring Integers
 *
 * Unless explicitly declared as unsigned, integer types are assumed to be
 * signed (exce pt for char, which the implementation can define as either a
 * signed or unsigned inte ger type). The following are valid declarations of
 * unsigned integers:
 *
 * 	unsigned int ui;		// unsigned is required
 * 	unsigned u;			// int can be omitted
 * 	unsigned long long ull2;	// int can be omitted
 * 	unsigned char uc;		// unsigned is required
 * 	When declaring signed integer types, you can omit the signed
 * keyword--except fo r signed char, which requires the keyword to distinguish
 * signed char from plain char . Unless it is the only keyword present, int can
 * also be omitted. For example, inste ad of declaring a variable to be of type
 * signed long long int, it is common practice to just declare it as long long
 * and save some typing. The following are all valid de clarations of signed
 * integers:
 *
 * 	int i;				// signed can be omitted
 * 	long long int sll;		// signed can be omitted
 * 	long long sll2;			// signed and int can be omitted
 * 	signed char sc;			// signed is required
 *
 * Unsigned Integers
 *
 * Unsigned integers have ranges that start at 0, and their upper bound is
 * greater than that of the corresponding signed integer type. Unsigned integers
 * are frequently used for counting items that may have large, nonnegative
 * quantities.
 *
 * Representation
 *
 * Unsigned integer types are easier to understand and to use than signed
 * integer types . They represent values using a pure binary system with no
 * offset: the least signifi cant bit has the weight 2^0, the next least
 * significant has the weight 2^1, and so f orth. The value of the binary number
 * is the sum of all the weights for the set bits. Table 3-1 shows some examples
 * of unsigned values using an unpadded 8-bit representation.
 *
 * 	Decimal		Binary		Hexadecimal
 * 	0		0000 0000	0x00
 * 	1		0000 0001	0x01
 * 	17		0001 0001	0x11
 * 	255		1111 1111	0xFF
 * 	Table 3-1: 8-Bit Unsigned Values
 *
 * 	Unsigned integer types do not require the sign to be represented and so
 * general ly provide 1 bit greater precision than the corresponding signed
 * integer types. Unsi gned integer values range from 0 to a maximum value that
 * depends on the width of the type. This maximum value is 2^N-1, where N is the
 * width. For example, most x86 archi tectures use 32-bit integers with no
 * padding bits, so an object of type unsigned int has a range of 0 to 2^32-1
 * (4,294,967,295). The constant expression UINT_MAX from <limits.h> specifies
 * the implementation-defined upper range for this type.
 *
 * Wraparound
 *
 * Wraparound occurs when you perform arithmetic operations that result in
 * values too small (less than 0) or too large (greater than 2^N-1) to be
 * represented as a particular unsigned integer type. In this case, the value is
 * reduced modulo the number that is one greater than the largest value that can
 * be represented in the resulting type. Wraparound is well-defined behaviour in
 * the C language. Whether it is a defect in your code depends on the context.
 * If you are counting something and the value wraps, it is likely to be an
 * error. However, the use of wraparound in certain encryption algorithms is
 * intentional.
 *    For example, the code in Listing 3-1 initializes ui to its maximum value
 * and then increments it. The resulting value cannot be represented as an
 * unsigned int, so it wraps around to 0. If this value is then decremented, it
 * falls outside the range once more, so it wraps around again to UINT_MAX.
 *    Because of wraparound, an unsigned integer expression can never evaluate
 * to less than 0. It's easy to lose track of this and implement comparisons
 * that are always true or always false. For example, the in the following for
 * loop can never take on a negative value, so this loop will never teminate:
 *
 *  for (unsigned int i = n; i >= 0; --i)
 *
 *    To avoid unplanned behaviour (such as having your airplane fall from the
 * sky), it's important to check for wraparound by using the limits from
 * <limits.h>. You should be careful when implementing these checks, because it
 * is easy to make mistakes. For example, the following code contains a defect
 * as sum + ui can never be larger than UINT_MAX:
 *
 *  extern unsigned int ui, sum;
 *  // assign values to ui and sum
 *  if (sum + ui > UINT_MAX)
 *    too_big();
 *  else
 *    sum = sum + ui
 *
 *    If the result of sum + ui is larger than UINT_MAX, it's a reduced modulo
 * UINT_MAX + 1. Therefore, this entire test is useless, and the generated code
 * will unconditionally perform the summation. Quality compiler might issue a
 * warning pointing this out, but not all do. To remedy this, we can subtract
 * sum from both sides of the inequality to form the following effective test:
 *
 *  extern unsigned int ui, sum;
 *  // assign values to ui and sum
 *  if (ui > UINT_MAX - sum)
 *    too_big();
 *  else
 *    sum = sum + ui;
 *
 *    UINT_MAX is the largest value that can be represented as an unsigned int,
 * and sum is a value between 0 and UINT_MAX. If sum is equal to UINT_MAX, the
 * result of the subtraction is 0, and if sum is equal to 0, the result of the
 * subtraction is UINT_MAX. Because the result of this operation will always
 * fall in the allowable range of 0 to UINT_MAX, it can never wrap.
 *    The same problem occurs when checking the result of an arithmetic
 * operation against 0, the minimum unsigned value:
 *
 *  extern unsigned int i, j;
 *  // assign values to i and j
 *  if (i - j < 0)  // cannot happen
 *    negative();
 *  else
 *    i = i - j;
 *
 *    Because unsigned integer values can never be negative, the subtraction
 * will be performed unconditionally. Quality compilers may warn about this
 * mistake as well. Instead of this useless test, we can check for wraparound by
 * testing whether j is greater than i:
 *
 *  if (j > i)  // correct
 *    negative();
 *  else
 *    i = i - j;
 *
 *    If j > i, the result would wrap around, so the possibility of wraparound
 * is clearly detected. By eliminating the subtraction operation in the test, we
 * eliminate the possibility of wraparound occurring during the test.
 *
 *  WARNING: Keep in mind that the width used when wrapping depends on the
 *  implementation, which means you can obtain different results on different
 *  platforms. Unless you take this into account, your code won't be portable.
 *
 * Signed Integers
 *
 * Each unsigned integer type (including _Bool) has a corresponding signed
 * integer type that occupies the same amount of storage. We use signed integers
 * to represent negative, zero, and positive values, the range of which depends
 * on the number of bits allocated to the type and representation.
 *
 * Representation
 *
 * You cannot choose which representation to use; that is determined by the
 * implementors of C for the various systems. Though all three are still in use,
 * two's complement is by far the most common representation.
 *    Signed integer types with width of N can represent any image value in the
 * range of -2^N-1 to 2^N-1. This means, for example, that an 8-bit value of
 * type signed char has a range of -128 to 127. Two's complement can represent
 * an additional most negative value. The most negative value for an 8-bit
 * signed char is -128, and it's absolute value |-128| cannot be represented as
 * this type. This leads to some interesting edge cases.
 *
 * Overflow
 *
 * Overflow occurs when a signed integer operation results in a value that
 * cannot be represented in the resulting type. For example, the following
 * implementation of a function-like macro that returns the absolute value of an
 * integer can overflow:
 *
 *  // undefined or wrong for most negative value
 *  #define Abs(i) ((i) < 0 ? -(i) : (i))
 * On the surface, this macro appears to correctly implement the absolute value
 * function by returning the nonnegative value of i without regard to its sign.
 * We use the conditional (?:) operator to test whether the value of i is
 * negative. If so, i is negated to -(i); otherwise, it evaluates to the
 * unmodified value (i).
 *    Because we've implemented Abs as a function-like macro, it can take an
 * argument of any type. Of course, invoking this macro with an unsigned integer
 * is pointless, because unsigned integers can never be negative, so the macro's
 * output would just reproduce the argument. However, we can invoke the function
 * with a variety of signed integer and floating-point types, as in the
 * following invocation:
 *
 *  signed int si = -25;
 *  signed int abs_si = Abs(si);
 *  printf("%d\n", abs_si); // prints 25
 *  In this example, we pass an object of type signed int with the value -25 as
 * an argument to the Abs macro. This invocation expands to the following:
 *
 *  signed int si = -25;
 *  signed int abs_si = ((si) < 0 ? -(si) : (si));
 *  printf("%d\n", abs_si); // prints 25
 *    The macro correctly returned the absolute value of -25. So far, so good.
 * The problem is that the negative of the two's complement most negative value
 * for a given type cannot be represented in that type, so this use of the Abs
 * function results in signed integer overflow. Consequently, this
 * implementation of Abs is defective and can do anything, including
 * unexpectedly returning a negative value:
 *
 *  signed int si = -25;
 *  signed int abs_si = Abs(si);  // undefined behaviour
 *  printf("%d\n", abs_si); // prints 25
 *    So, what should Abs(INT_MIN) return to fixx this behaviour? Signed integer
 * overflow is undefined behaviour in C, allowing implementations to silently
 * wrap (the most common behaviour), trap, or both. Traps interrupt execution of
 * the program so that no further operations are performed. Common architectures
 * like x86 do a combination of both. Because the behaviour is undefined, no
 * universally correct solution to this problem exists, but we can at least test
 * for the possibility of undefined behaviour before it occurs and take
 * appropriate action.
 *    To make the absolute-value macro useful for variety of types, we'll add a
 * type-dependent flag argument to it. The flag represents the *_MIN macro,
 * which matches the type of the first argument. This value is returned in the
 * problem case:
 *
 *  #define AbsM(i, flag) ((i) >= 0 ? (i) : ((i) == flag) ? (flag) : -(i)))
 *  signed int si = -25;  // try INT_MIN to trigger the problem case
 *  if (abs_si == INT_MIN)
 *    goto recover;
 *  else
 *    printf("%d\n", abs_si); // prints 25
 *
 *    The AbsM macro tests for the most negative value and simply returns it if
 * found instead of triggering the undefined behaviour by negating it.
 *    On some systems, the C Standard Library implements the following int-only
 * absolute-value function to avoid overflow then the function is passed INT_MIN
 * as an argument:
 *
 *  int abs(int i) {
 *    return (i >= 0) ? i : -(unsigned)i; // avoids overflow
 *  }
 *
 *    In this case, i is converted to an unsigned int and negated.
 *    Perhaps surprisingly, unary minus (-) operator is defined for unsigned
 * integer types. The resulting unsigned integer value is reduced modulo the
 * number that is one greater than the largest value that can be represented by
 * the resulting type. Finally, i is implicitly converted back to signed int as
 * required by the return statement. Because -INT_MIN can't be represented as a
 * signed int, the result is implementation-defined. This is why this
 * implementation is used only on some systems, and even on these systems, the
 * abs function returns an incorrect value.
 *    The Abs and AbsM implementations use function-like macros to evaluate
 * their parameters more than once. This can cause surprises when the arguments
 * cause program state to change. These are called side effects. Function calls,
 * on the other hand, evaluate each argument only once.
 *    Unsigned integers have well-defined wraparound behaviour. Signed integer
 * overflow, or the possibility of it, should always be considered a defect.
 *
 * Integer Constants
 */
#include <limits.h>
#include <stdio.h>

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) >= 0 ? (i) : ((i) == (flag) ? (flag) : -(i)))

int _abs(int i) {
  return (i >= 0) ? i : -(unsigned)i; // avoids overflow
}

int main(void) {
  unsigned int ui = UINT_MAX; // 4,294,967,295 on x86
  ui++;
  printf("ui = %u\n", ui); // ui is 0
  ui--;
  printf("ui = %u\n", ui); // ui is 4,294,967,295

  signed int si = INT_MIN;
  signed int abs_si = Abs(si);
  printf("%d\n", abs_si);
  if (si == abs_si)
    printf("Integer overflow didn't occur\n");

  abs_si = AbsM(si, INT_MIN);
  printf("%d\n", abs_si);
  if (si == abs_si)
    printf("Integer overflow didn't occur\n");

  printf("Result: %d\n", _abs(INT_MIN));
  return 0;
}
