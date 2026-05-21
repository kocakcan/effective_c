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
 *
 * Declaring Multiple Variables
 *
 * You can declare multiple variables in any single declaration, but doing so can get 
 * confusing if the variables are pointers or arrays, or the variables are different
 * types. For example, the following declarations are all correct:
 *
 * 	char *src, c;
 * 	int x, y[5];
 * 	int m[12], n[15][3], o[21];
 * The first line declares two variables, src and c, which have differen types. The src
 * variable has a type of char *, and c has a type of char. The second line again decl-
 * ares two variables, x and y, with different types. The variable x has a type int, a-
 * nd y is an array of five elements of type int. The third line declares three arrays
 * --m, n, and o--with different dimensions and numbers of elements. These declarations
 *  are easier to understand if each is on its own line:
 * 	char *src;	// src has a type of char *
* 	char c;		// c has a type of char
* 	int x;		// x has a type of int
* 	int y[5];	// y is an array of 5 elements of type int
* 	int m[12];	// m is an array of 12 elements of type int
* 	int n[15][13]	// n is an array of 15 arrays of 3 elements of type int
* 	int o[21];	// o is an array of 21 elements of type int
* Readable and understandable code is less likely to have defects.
*
* Swapping Values (First Attempt)
*
* Each object has a storage duration that determines its lifetime, which is the time during program execution for which the object exists, has storage, has a constant add-
* ress, and retains its last-stored value. Objects must not be referenced outside their
* lifetime.
*
* Local variables such as a and b from Listing 2-1 have automatic storage duraiton, me-aning that they exist until execution leaves the block in which they're defined. We are
* going to attempt to swap the values stored in these two variables. Listing 2-2 is our
* first attempt to implement the swap function.
*
* 	void swap(int a, int b) {
*		int t = a;
*		a = b;
*		b = t;
*		printf("swap: a = %d, b = %d\n", a, b);
*	}
*	Listing 2-2: The swap function
* The swap function declares two parameters, a and b, that you use to pass arguments to
* this function. C distinguishes between parameters, which are objects declared as part
* of the function declaration that acquire a value on entry to the function, and argum-
* ents, which are comma-separated expressions you include in the function call express-
* ion. We also declare a temporary variable t of type int in the swap function and init
* ialize it to the value of a. This variable is used to temporarily save the value sto-
* red in a so that it is not lost during the swap.
*
* The variables a and b were initialized to 21 and 17, respectively. The first call to
* printf within the swap function shows these two values swapped, but the second call 
* to printf in main shows the original values unchanged.
*
* C is a call-by-value (also called pass-by-value) language, which means that when you
* provide an argument to a function, the value of that argument is copied into a disti-
* nct variable for use within the function. The swap function assigns the values of the
* objects you pass as arguments to the respective parameters. When the values of the pa
* rameters in the function are changed, the values in the caller are unaffected because
* they are distinct objects. Consequently, the variables a and b retain their original
* values in main during the second call to printf. The goal of the program was to swap
* the values of these two objects. By testing the program, we've discovered it has a
* bug, or defect.
 */
#include <stdio.h>

void swap(int a, int b) {
	a ^= b;
	b ^= a;
	a ^= b;
	printf("swap: a = %d, b = %d\n", a, b);
}

int main(void) {
	int a = 21, b = 17;
	swap(a, b);
	printf("main: a = %d, b = %d\n", a, b);
	return 0;
}
