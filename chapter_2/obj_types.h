/***
 * 					Object Types
 * Boolean Types
 *
 * Objects declared as _Bool can store only the values 0 and 1. This Boolean
 * type was introduced in C99, and starts with an underscore to differentiate it
 * in that had al ready declared their own identifiers named bool or boolean.
 * Identifiers that begin with an underscore and either an uppercase letter or
 * another underscore are always reserved. The idea is that the C Standard
 * committee can create new keywords such _B ool, assuming that you have avoided
 * the use of reserved identifiers. If you haven't , as far as the C Standards
 * committee is concerned, it is your fault for not readin g the standard
 * carefully. If you include the header <stdbool.h>, you can also spell this
 * type as bool an d assign it the values true (which expands to the integer
 * constant 1) and false (wh ich expands to the integer constant 0). Here we
 * declare two Boolean variables using both spellings of the type name:
 *
 * 	#include <stdbool.h>
 * 	_Bool flag1 = 0;
 * 	bool flag2 = false;
 * 	Both spellings will work, but it is better to use bool, as this is the
 * long-te rm direction for the language.
 *
 * Character Types
 *
 * The C language defines three character types: char, signed char, and unsigned
 * char. Each compiler implementation will define char to have the same
 * alignment, size, ran ge, representation, and behaviour as either signed char
 * or unsigned char. Regardles s of the choice made, char is a separate type
 * from the other two and is compatible with both. The char type is commonly
 * used to represent character data in C language progr ams. In particular,
 * objects of type char must be able to represent the minimum set of characters
 * required in the execution environment (known as the basic execution character
 * set), including upper-and lowercase letters, the 10 decimal digits, the s
 * pace character, and various punctuation and control characters. The char type
 * is in appropriate for integer data; it is safer to use signed char to
 * represent small sig ned integer values, and unsigned char to represent small
 * unsigned values. The basic execution character set suits the needs of many
 * conventional data pr ocessing applications, but its lack of non-English
 * letters is an obstacle to accept ance by international users. To address this
 * need, the C Standard committee specifi ed a new, wide type to allow large
 * character sets. You can represent the characters of a large character set a
 * wide characters by using the wchar_t type, which general ly takes more space
 * than a basic character. The C Standard Library provides functio ns that
 * support both narrow and wide character types.
 *
 * Numerical Types
 *
 * C provides several numerical types that can be used to represent integers,
 * enumerat ors, and floating-point values.
 *
 * Signed integer types can be used to represent negative numbers, positive
 * numbers, a nd zero. The signed integer types include signed char, short int,
 * int, long int, an d long long int. Except for int itself, the keyword int may
 * be omitted in the declarations for these types, so you might, for example,
 * declare a type by using long long instead o f long long int. For each signed
 * integer type, there is a corresponding unsigned integer type t hat uses the
 * same amount of storage: unsigned char, unsigned short int, unsigned in t,
 * unsigned long int, and unsigned long long int. The unsigned types can be used
 * to represent only positive numbers and zero. The signed and unsigned integer
 * types are used to represent integers of variou s sizes. Each platform
 * (current or historical) determines the size for each of thes e types, given
 * some constraints. Each type has a minimum representable range. The t ypes are
 * ordered by width, guaranteeing that wider types are at least as large as n
 * arrower types so that an object of type long long int can represent all
 * values that an object of type long int can represent, an object of type long
 * int can represent all values that can be represented by an object of type
 * int, and so forth. The actu al size of the various integer types can be
 * inferred from the minimum and maximum r epresentable values for the various
 * integer types specified in the <limits.h> heade r file. The int type usually
 * has the natural size suggested by the architecture of the execution
 * environment, so the size would be 16 bits wide on a 16-bit architecture, and
 * 32 bits wide on a 32-bit architecture. You can specify actual width integers
 * us ing type definitions from the <stdint.h> or <inttypes.h> headers, like
 * uint32_t. T hese headers also provide type definitions for the widest
 * available integer types: uintmax_t and intmax_it.
 *
 * enum Types
 *
 * An enumeration, or enum, allows you to define a type that assign names
 * (enumerators ) to integer values in cases with an enumerable set of constant
 * values. The followi ng are examples of enumerations:
 *
 * 	enum day { sun, mon, tue, wed, thu, fri, sat };
 *	enum cardinal_points { north = 0, east = 90, sout = 180, west = 270 };
 *	enum months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov,
 * dec }; If you don't specify a value to the first enumerator with the =
 * operator, the value of its enumeration constant is 0, and each subsequent
 * enumerator without an = adds 1 to the value of the previous enumeration
 * constant. Consequently, the value of sun in the day enumeration is 0, mon is
 * 1, and so forth. You can also assign specific values to each enumerator, as
 * shown by the cardin al_points enumeration. Using = with enumerators may
 * produce enumeration constants w ith duplicate values, which can be a problem
 * if you incorrectly assume all the valu es are unique. The montsh enumeration
 * sets the first enumerator at 1, and each subs equent enumerator that isn't
 * specifically assigned a value will be incremented by 1
 * .
 * 	The actual value of the enumeration constant must be representable as an
 * int, but its type is implementation defined. For example, Visual C++ uses a
 * signed int, and GCC uses an unsigned int.
 *
 * Floating-Point Types
 *
 * The C language supports three floating-point types: float, double, and long
 * double. Floating-point arithmetic is similar to, and often as a model for
 * arithmetic for re al numbers. The choice of floating-point representation is
 * implementation dependent
 * .
 *
 * void Types
 *
 * The void type is a rather strange type. The keyword void (by itself) means
 * "cannot hold any value." For example, you can use it to indicate that a
 * function doesn't re turn a value, or as the sole parameter of a function to
 * indicate that the function takes no arguments. On the other hand, the derived
 * type void * means that the point er cab reference any object.
 */
