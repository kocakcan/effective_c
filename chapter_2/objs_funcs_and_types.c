/***
 * Objects, Functions, Types, and Pointers
 *
 * Every type in C is either an object type or a function type.
 *
 * An object is storage in which you can represent values. To be precise, an object is
 * defined by the C Standard as a "region of data storage in the execution environment,
 * the contents of which can represent values," with the added note, "when referenced,
 * an object can be interpreted as having a particular type." A variable is an example
 * of an object.
 *
 * Variables have a declared type that tells you the kind of object its value represe-
 * nts. For example, an object with type int contains an integer value. The type is im-
 * portant because the collection of bits that represent one type of object will likely
 * have a different value if interpreted as a different type of object. For example, t-
 * he number 1 is represented in IEEE 754 by the bit pattern 0x3f800000 but if you were
 * to interpret this same bit pattern as an integer, you'd get the value 1,065,353,216
 * instead of 1.
 *
 * Functions are not objects but do have types. A function type is characterized by bo-
 * th its return type as well as the number and types of bits parameters.
 *
 * The C language also has pointers, which can be thought of as an address--a location
 * in memory where an object or function is stored. A pointer type is derived from the
 * referenced type T is called a pointer to T.
 *
 * Because objects and functions are different things, object pointers and function po-
 * inters are also different thing, and should not be used interchangeably.
 *
 * Declaring Variables
 *
 * When you declare a variable, you assign it a type and provide it a name, or identif-
 * ier, by which to reference the variable.
 * Listing 2-1 declares two integer objects with initial values. This simple program
 * also declares, but doesn't define, a swap function to swap those values.
 *
 * 	#include <stdio.h>
 *
 * 	int main(void) {
 * 		int a = 21;
 * 		int b = 17;
 *
 * 		swap(a, b);
 * 		printf("main: a = %d, b = %d\n", a, b);
 * 		return 0;
 * 	}
 * 	Listing 2-1: Program meant to swap two integers
 * This example program shows a main function with a single code block between the { }
 * characters. This kind of code block is also known as a compound statement. We defi-
 * ne two variables, a and b, within the main function. We declare the variables as ha-
 * ving the type int and initialize them to 21 and 17, respectively. Each variable must
 * have a declaration. The main function then calls the swap function to try to swap
 * the values of the two integers. The swap function is declared in this program, but
 * not defined.
 */
#include <stdio.h>

int main(void) {
	int a = 21, b = 17;
	a ^= b;
	b ^= a;
	a ^= b;
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
