/**
 * An operator is a keyword or one or more punctuation characters used to
 * perform an operation. When an operator is applied to one or more operands, it
 * becomes and expression that computes a value and that might have side
 * effects. Expressions are sequences of operators and operands that compute a
 * value or accomplish another purpose. The operands can be identifiers,
 * constants, string literals, and other expressions.
 *
 * Simple Assignment
 *
 * A simple assignment replaces the value stored in the object designated by the
 * left operand with the right operand. The value of the right operand is
 * converted to the type of the assignment expression. Simple assignment has
 * three components: the left operand, the assignment operator (=), and the
 * right operand, as shown in the following example:
 *
 *  int i = 21; // declaration with initializer
 *  int j = 7;  // declaration with initializer
 *  i = j;      // simple assignment
 *    The first two lines are declarations that define and initialize i with
 * the value 21, and j with the value 7. An initializer uses an expression but
 * is not itself an assignment expression, because an initializer is always part
 * of a declaration.
 *    The third line contains a simple assignment. You must define or declare
 * all identifiers that appear in an expression such as simple assignment for
 * your code to compile.
 *    In simple assignment, the rvalue is converted to the type of the lvalue
 * and then stored in the object designated by the lvalue. In the assignment i =
 * j, the value is read from j and written to i. Because both i and j are the
 * same type (int), no conversion is necessary. The assignment expression has
 * the value of the result of the assignment and the type of the lvalue.
 *    The left operand in simple assignment is always an expression (with an
 * object type other than void), and we refer to it as an lvalue. The l in
 * lvalue originally comes from it being the left operand, but it may be more
 * correct to think of it as a standing for locator value, because it must
 * designate an object. In this example, the identifiers for both objects i and
 * j are lvalues. An lvalue can also be an expression such *(p + 4), provided it
 * references an object in memory.
 *    The right operand is also an expression but can simply be a value and does
 * not need to identify an object. We refer to this value as an rvalue (right
 * operand) or expression value. The rvalue does not need to refer to an object,
 * as you can see in the following statement, which uses the types and values
 * from the preceeding example:
 *
 *  j = i + 12; // j now has the value 19
 *    The expression i + 12 is not an lvalue, because there is no underlying
 * object storing the result. Instead, i by itself is an lvalue that is
 * automatically converted into an rvalue to be used as an operand to the
 * addition opearation. The resulting value from the addition operation (which
 * has no memory location associated with it) is also an rvalue. C constrains
 * where lvalues and rvalues may appear. The following statements illustrate the
 * correct and incorrect use of lvalues and rvalues:
 *
 *  int i;
 *  i = 5;      // i is an lvalue, 5 is an rvalue
 *  int j = i;  // lvalues can appear on the right-hand side of an assignment
 *  7 = i;      // error: rvalues can't appear on the left-hand side of an
 * assignment
 *    The assignment 7 = i won't work, because the rvalue must always go on the
 * right side of the operator. In the following example, the right operand has a
 * different type than the assignment expression, so the value of i is first
 * converted to a signed char type. The value of the expression enclosed in
 * parantheses is then converted to the long int type:
 *
 *  signed char c;
 *  int i = INT_MAX;
 *  long k;
 *  k = (c = i);
 *    Assignment must deal with real-world constraints. Specifically, simple
 * assignment can result in truncation if a value is converted to a narrower
 * type. To prevent values from being truncated, make sure that you choose a
 * sufficiently wide type that can represent any value that might arise, or
 * check for overflow.
 *
 * Evaluations
 *
 * Now that we've looked at simple assignment, let's step back for a moment and
 * look at how expressions are actually evaluated. Evaluation mostly means
 * simplifying an expression down to a single value. However, the evaluation of
 * an expression can include both value computations and the initiation of side
 * effects.
 *    A value computation is the calculation of the value that results from the
 * evaluation of the expression. Computing the final value may involve
 * determining the identity of the object or reading the value previously
 * assigned to an object. For example, the following expression contains several
 * value computations to determine the identity of i, a, and a[i]:
 *
 *  a[i] + f() + 9
 *
 *    Because f is a function and not an object, the expression f() does not
 * involve determining the identity of f. The value computations of operands
 * must occur before the value computation of the result of the operator. In
 * this example, separate value computations read the value of a[i] and
 * determine the value returned by the call to function f. A third computation
 * then sums these values to obtain the value returned by the overall
 * expression. If a[i] is an array of int, and f() returns an int, the result of
 * the expression will have the type int.
 *    Side effects are changes to the state of the execution environment. Side
 * effects include writing to an object, accessing (reading or writing) a
 * volatile-qualified object, I/O, assignment, or calling a function that does
 * any of these things. The previous example can be slightly modified to add an
 * assignment. Updating the stored value of j is a side effect of the
 * assignment:
 *
 *  int j;
 *  j = a[i] + f() + 9;
 *
 *  The assignment to j is a side effect that changes the state of the execution
 * environment. Depending on the definition of the f function, the call to f may
 * also have side effects.
 *
 * Function Invocation
 *
 * A function designator is an expression that has function type and is used to
 * invoke a function. In the following function invocation, max is the function
 * designator:
 *
 * 	int x = 11;
 * 	int y = 21;
 * 	int max_of_x_and_y = max(x, y);
 *
 * 	The max function returns the larger of its two arguments. In an express
 * ion, a function designator is converted to pointer-to-function returning typ
 * e at compile time. The value of each argument must be of a type that can be
 * assigned to an object with (the unqualified version of) the type of its corr
 * esponding parameter. The number and type of the arguments need to agree with
 * the number and type of the parameters accepted by the function. Here, that m
 * eans two integer arguments. C also supports variadic functions, which can ac
 * cept a variable of number of arguments (the printf function is an example of
 * a variadic function).
 * 	We can also pass one function to another, as shown by Listing 4-1:
 *
 * 	int f(void) {
 *		// --snip--
 *		return 0;
 *	}
 *	void g(int (*func)(void)) {
 *		// --snip--
 *		if (func() != 0)
 *			printf("g failed\n");
 *			// --snip--
 *	}
 *	// --snip--
 *	g(f);	// call g with function-pointer argument
 *	// --snip--
 *	Listing 4-1: Passing one function to another function
 *
 *	This code passes the address of a function designated by f to another f
 * unction, g. The function g accepts a function pointer to a function that acc
 * epts no arguments and returns int. A function passed as an argument is impli
 * citly converted to a function pointer. The definition of g makes this explic
 * it; an equivalent declaration is void g(int func(void)).
 *
 * Increment and Decrement Operators
 *
 * The increment (++) and decrement (--) operators increment and decrement a
 * modifiable lvalue, respectively. Both are unary operators, because they take
 * a single operand.
 *    These operators can be used as either prefix operators, which come before
 * the operand, or postfix operators, which come after the operand. The prefix
 * and postfix operators have different behaviours, which means they are
 * commonly used as trick questions in quizzes and interviews. A prefix
 * increment performs the increment before returning the value, whereas a
 * postfix increment returns the value and then performs the increment. Listing
 * 4-2 illustrates these behaviours by performing a prefix or postfix increment
 * or decrement operation and then assigning the result to e.
 *
 *  int i = 5;
 *  int e;      // result of the expression
 *  e = i++;    // postfix increment: i has the value 6; e has the value 5
 *  e = i--;    // postfix decrement: i has the value 5; e has the value 6
 *  e = ++i;    // prefix increment:  i has the value 6; e has the value 6
 *  e = --i;    // prefix decrement:  i has the value 5; e has the value 5
 *  Listing 4-2: Prefix and postfix increment and decrement operators
 *
 *    The i++ operation in this example returns the unchanged value 5, which is
 * then assigned to e. The value of i is then incremented as a side effect of
 * the operation.
 *    The prefix increment operator increments the value of the operand, the
 * expression returns the new value of the operand after it has been
 * incremented. Consequently, the expression ++i is equivalent to i = i + 1,
 * except that i is evaluated only once. The ++i operation in this example
 * returns the incremented value 6, which is then assigned to e.
 * */
#include <stdio.h>

int f(void) {
  puts("f is called");
  return 0;
}

void g(int (*func)(void)) {
  if (func() != 0)
    puts("g failed");
  // (*func)();
  func();
  return;
}

int main(void) {
  f();
  g(f);
  return 0;
}
