#include <stdio.h>
#include <stdlib.h>

int main(void) {
  if (puts("Hello, world!") == EOF) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
/***
 * EXIT_SUCCESS is an object-like macro that commonly expands to 0 and is
 * typically defined as follow:
 *
 * 	#define EXIT_SUCCESS	0
 * A return from the initial call to the main function is equivalent to calling
 * the C Standard Library exit function with the value returned by the main
 * function as its argument.
 *
 * Checking Function Return Values
 *
 * Functions will often return a value that's the result of a computation or
 * that signifies whether the function successfully completed its task. For
 * example, the puts function we used in our "Hello, world!" program takes a
 * string to print and returns a value of type int. The puts function returns
 * the value of the macro EOF (a negative integer, -1) if a write error occurs;
 * otherwiser it returns a non-negative integer value.
 *
 * Although it's unlikely that the puts function will fail and return EOF for
 * this simple program, it's possible. Because the call to puts can fail and
 * return EOF, it means that your first C program has a bug, or, at least, can
 * be improved as follows:
 *
 * 	#include <stdio.h>
 * 	#include <stdlib.h>
 *
 * 	int main(void) {
 * 		if (puts("Hello, world!") == EOF) {
 * 			return EXIT_FAILURE;
 *			// code here never executes
 *		}
 *		return EXIT_SUCCESS;
 *		// code here never executes
 * This revised version of the "Hello, world!" program checks whether the puts
 * call returns the value EOF, indicating a write error. If the function returns
 * EOF, the program retu- rns the value of the EXIT_FAILURE macro (which
 * evaluates to nonzero value). Otherwise, the function succeeds, and the
 * program returns EXIT_SUCCESS (which is required to be 0). The script that
 * invokes the program can then check its status to determine whether it w as
 * successful. Code following a return statement is dead code that never
 * executes. This is indicated by single line comments in the revised program.
 * Everything following // is ignored by the compiler.
 *
 * Formatted Output
 *
 * The puts function is a nice, simple way to write a string to stdout, but
 * eventually you'll need to print formatted output using the printf
 * function--for example, to print arguments o- ther than strings. The printf
 * function takes a format string that defines how the output is formatted,
 * followed by a variable number of arguments that are the actual values you
 * want to print. For example, if you want to use the printf function to print
 * our Hello, world!, you could write it like this:
 *
 * 	printf("%s\n", "Hello, world!");
 * The first argument is the format string "%s\n". The %s is a conversion
 * specification that in- structs the printf function to read the second
 * argument (a string literal) and print it to st- dout. The \n is an alphabetic
 * escape sequence used to represent nongraphic characters, and t- ells the
 * function to include a new line after the string. Without the newline
 * sequence, the ne- xt characters printed (likely the command prompt) would
 * appear on the same line. This function call outputs the following:
 *
 * 	Hello, world!
 * Take care not to pass user-supplied data as part of the first argument to the
 * printf function, because doing so can result in a formatted output security
 * vulnerability.
 *
 * The simplest way to output a string is to use the puts function, as
 * previously shown. If you do use printf instead of puts in the revised version
 * of the "Hello, world!" program, you'll find it no longer works, because the
 * printf function returns status differently than the puts func- tion. The
 * printf function returns the number of characters printed if it's successful,
 * or a ne- gative value if an output or encoding error occurred. You can try
 * modifying the "Hello, world!" program to use the printf function as an
 * exercise.
 */
