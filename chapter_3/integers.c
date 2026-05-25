/***
 * 					Integers
 *
 * Each integer type represents a finite range of integers. Signed integer types repres
 * ent values that can be negative, zero, or positive; unsigned integers represent valu
 * es that can be only zero or positive. The range that each type of integer can repres
 * ent depends on your implementation.
 * 	The value of an integer object is the ordinary mathematical value stored in the
 * object. The representation of a value for an integer object is the particular encodi
 * ng of the value in the bits of the objects's allocated storage.
 *
 * Padding and Precision
 *
 * All integer types except char, signed char, and unsigned char may contain unused bit
 * s, called padding, that allow implementation to accommodate hardware quirks (such as
 * skipping over a sign bit in the middle of a multiple-word representation) or to opti
 * mally align with a target architecture. The number of bits used to represent a value
 * of a given type, excluding padding but including the align, is called width and is o
 * ften denoted by N. The precision is the number of bits used to represent value, excl
 * uding sign and padding bits.
 *
 * The <limits.h> Header File
 *
 * The <limits.h> header file provides the minimum and maximum representable values for
 * the various integer types. A representable value is one that can be represented in t
 * he number of bits available to an object of a particular type. Values that cannot be
 * represented will be diagnosed by the compiler or converted to a representable but di
 * fferent (incorrect) value. Compiler writers provide the correct minimum, maximum, an
 * d width values for their implementations. To write portable code, you should use the
 * se constants, rather than integer literals such as +214783647 that represent a speci
 * fic limit and may change when porting to a different implementation.
 * 	The C Standard imposes only three constraints on integer sizes. First, storage 
 * for every data type occupies an integral number of adjacent unsigned char objects ( 
 * which may include padding). Second, each integer type has to support the minimum ran
 * ges, allowing you to depend on a portalbe range of values across any implementation.
 * Third, smaller types cannot be wider than larger types. So, for example, USHRT_MAX c
 * annot be greater than UINT_MAX, but they can be the same width.
 *
 * Declaring Integers
 *
 * Unless explicitly declared as unsigned, integer types are assumed to be signed (exce
 * pt for char, which the implementation can define as either a signed or unsigned inte
 * ger type). The following are valid declarations of unsigned integers:
 *
 * 	unsigned int ui;		// unsigned is required
 * 	unsigned u;			// int can be omitted
 * 	unsigned long long ull2;	// int can be omitted
 * 	unsigned char uc;		// unsigned is required
 * 	When declaring signed integer types, you can omit the signed keyword--except fo
 * r signed char, which requires the keyword to distinguish signed char from plain char
 * . Unless it is the only keyword present, int can also be omitted. For example, inste
 * ad of declaring a variable to be of type signed long long int, it is common practice
 * to just declare it as long long and save some typing. The following are all valid de
 * clarations of signed integers:
 *
 * 	int i;				// signed can be omitted
 * 	long long int sll;		// signed can be omitted
 * 	long long sll2;			// signed and int can be omitted
 * 	signed char sc;			// signed is required
 *
 * Unsigned Integers
 *
 * Unsigned integers have ranges that start at 0, and their upper bound is greater than
 * that of the corresponding signed integer type. Unsigned integers are frequently used
 * for counting items that may have large, nonnegative quantities.
 *
 * Representation
 *
 * Unsigned integer types are easier to understand and to use than signed integer types
 * . They represent values using a pure binary system with no offset: the least signifi
 * cant bit has the weight 2^0, the next least significant has the weight 2^1, and so f
 * orth. The value of the binary number is the sum of all the weights for the set 
 * bits. Table 3-1 shows some examples of unsigned values using an unpadded 8-bit
 * representation.
 *
 * 	Decimal		Binary		Hexadecimal
 * 	0		0000 0000	0x00
 * 	1		0000 0001	0x01
 * 	17		0001 0001	0x11
 * 	255		1111 1111	0xFF
 * 	Table 3-1: 8-Bit Unsigned Values
 *
 * 	Unsigned integer types do not require the sign to be represented and so general
 * ly provide 1 bit greater precision than the corresponding signed integer types. Unsi
 * gned integer values range from 0 to a maximum value that depends on the width of the
 * type. This maximum value is 2^N-1, where N is the width. For example, most x86 archi
 * tectures use 32-bit integers with no padding bits, 
 */
