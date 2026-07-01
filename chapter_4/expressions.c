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
 *
 * Operator Precedence and Associativity
 *
 * In mathematics and computer programming, the order of operations (or operator
 * precedence) is a collection of rules that dictate the order in which
 * operations are performed in a given expression. Associativity determines how
 * operators of the same precedence are grouped when no explicit parantheses are
 * used. If adjacent operators have equal precedenc, the choice of which
 * operation to apply first is determined by the associativity. Left-associative
 * operators cause the operations to be grouped from the left while
 * right-associative operators cause the operations to be grouped from the
 * right. Grouping can be thought of as the implicit introduction of
 * parantheses.
 *
 *  Precedence  Operator      Description  Associativity 0           (...)
 *   Forced grouping                                 Left 1           ++ --
 *    Postfix increment and decrement
 *              ()            Function call
 *              []            Array subscripting
 *              .             Structure and union member access
 *              ->            Structure and union member access through
 *                            pointer
 *              (type){list}  Compound literal
 *  2           ++ --         Prefix increment and decrement  Right
 *              + -           Unary plust and minus
 *              ! ~           Logical NOT and bitwise NOT
 *              (type)        Type cast
 *              *             Indirection (dereference)
 *              &             Address-of
 *              sizeof        Size of
 *              _Alignof      Alignment requirement
 *  3           * / %         Multiplication, division, and remainder  Left 4
 *        + -           Addition and subtraction 5           << >>  Bitwise left
 * shift and right shift 6           < <=          Relational operators < and <=
 *              > >=          Relational operators > and >=
 *  7           == !=         Equal to and not equal to
 *  8           &             Bitwise AND
 *  9           ^             Bitwise XOR (exclusive or)
 *  10          |             Bitwise OR (inclusive or)
 *  11          &&            Logical AND
 *  12          ||            Logical OR
 *  13          ?:            Conditional operator
 *  14          =             Simple assignment
 *              += -=         Assignment by sum and difference
 *              *= /= %/      Assignment by product, quotient, and remainder
 *              <<= >>=       Assignment by bitwise left shitf and right shift
 *              &= ^= |=      Assignment by bitwise AND, XOR, and OR
 *  15          ,             Expression sequencing
 *
 *     Sometimes operator precedence can be intuitive, and sometimes it can be
 * misleading. For example, the postfix ++ and -- operators have higher
 * precedence than both prefix ++ and -- operators, which in turn have the same
 * precedence as the unary * operator. Moreover, if p is a pointer, then *p++ is
 * equivalent to *(p++), and ++*p is equivalent to ++(*p), because both the
 * prefix ++ operator and the unary * operator are right-associative. If two
 * operators have the same precedence and association, they are evaluated from
 * left to right. Listing 4-3 illustrates the precedence rules among the
 * operators.
 *
 *  char abc[] = "abc";
 *  char xyz[] = "xyz";
 *
 *  char *p = abc;
 *  printf("%c", ++*p);
 *
 *  p = xyz;
 *  printf("%c", *p++);
 *  Listing 4-3: Operator precedence
 *    The pointer in the expression ++*p is first dereferenced, producing the
 * character 'a'. This value is then incremented, resulting in the character
 * 'b'. On the other hand, the pointer in the expresion *p++ is incremented
 * first, so it refers to the 'y' character. However, the result of postfix
 * increment operators is the value of the operand so that the original pointer
 * value is dereferenced, producing the 'x' character. Consequently, this code
 * prints outs the character bx. You can use parantheses () to change or clarify
 * the order of operations.
 *
 * Order of Evaluation
 *
 * The order of evaluation of the operands of any C operator, including the
 * order of evaluation of any subexpressions, is generally unspecified. The
 * compiler will evaluate them in any order, and may choose a different order
 * when the same expression is evaluated again. This latitude allows the
 * compiler to produce faster code by choosing the most efficient order. The
 * order of evaluation is constrained by operator precedence and associativity.
 * 	Listing 4-4 demonstrates the order of evaluation for function arguments.
 * We invoke the max function we defined earlier with two arguments, which are
 * the result of calling functions f and g, respectively. The order of
 * evaluation of the expressions passed to max is unspecified, meaning that f
 * and g could be called in either order.
 *
 * 	int glob;	// static storage initialized to 0
 *
 * 	int f(void) {
 *		return glob + 10;
 *	}
 *
 *	int g(void) {
 *		glob = 42;
 *		return glob;
 *	}
 *
 *	int main(void) {
 *		int max_value = max(f(), g());
 *		// --snip--
 *	}
 *	Listing 4-4: Order of evaluation for function arguments
 * The global variable glob is accessed by both functions f and g, meaning they
 * rely on shared state. When calculating their return value, the values passed
 * as arguments to max may differ between compilations. If f is called first, it
 * will return 10, but if it is called last, it will return 52. Function g
 * always returns 42 regardless of the order of evaluation. Consequently, the
 * max function (which returns the greater of the two values) may return either
 * 42 or 52, depending on the order of evaluation of its arguments. The only
 * sequencing guarantees provided by this code are that both f and g are called
 * before max, and that the executions of f and g do not interleave.
 * 	This code can be rewritten to ensure it always behaves in a predictable,
 * portable manner:
 *
 * 	int f_val = f();
 * 	int g_val = g();
 * 	int max_value = max(f_val, g_val);
 *
 * 	In this revised program, f is called to initialize the variable f_val.
 * This is guaranteed to be sequenced before the execution of g, which is called
 * in the subsequent declaration to initialize the variable g_val. If one
 * evaluation is sequenced before another evaluation, the first evaluation must
 * complete before the second evaluation can begin. You can use sequence points
 * to guarantee, for example, that an object will be written before it is read
 * as part of a separate evaluation. The execution of f is guaranteed to be
 * sequenced before the execution of g because a sequence point exists between
 * the evaluation of one full expression and the next full expression.
 *
 * Unsequenced and Indeterminately Sequenced Evaluations
 *
 * The executions of unsequenced evaluations can interleave, meaning that the
 * instructions can be executed in any order, provided that the execution is
 * sequentially consistent that reads and writes are performed in the order
 * specified by the program.
 * 	Some evaluations are indeterminately sequenced, which means they cannot
 * interleave but can still be executed in any order. For example, the following
 * statement contains several value computations and side effects:
 *
 * 	printf("%d\n", ++i, ++j * --k);
 *
 * 	The values of i, j, and k must be read before their values can be
 * incremented or decremented. This means that the reading of i must be
 * sequenced before the increment side effect, for example. Similarly, all side
 * effects for the operands of the multiplication operation need to complete
 * before the multiplication can occur. Finally, the multiplication has to
 * complete before the addition because of operator precedence rules, and all
 * side effects must complete for the operands of the addition operation before
 * it can occur. These constraints produce a partial ordering among these
 * operations, because they don't require that j is incremented before k is
 * decremented, for example. Unsequenced evaluations in this expression can be
 * performed in any order. This allows the compiler to reorder operations and
 * cache values in registers, allowing for faster overall execution. Function
 * executions, on the other hand, are indeterminately sequenced and do not
 * interleave with each other.
 *
 * Sequence Points
 *
 * A sequence point is the juncture at which all side effects will have
 * completed. These are implicitly defined by the language, but you can control
 * where they occur by the way you specify your program logic.
 * 	A sequence point occurs between the evaluation of one full expression
 * (an expression that is not part of another expression or declarator) and the
 * next full expression to be evaluated. A sequence point also occurs upon
 * entering or exiting a called function.
 * 	If a side effect is unsequenced relative to either a different side
 * effect on the same scalar object, the code has undefined behaviour. A scalar
 * type is either an arithmetic type or pointer type. The expression i++ * i++
 * in the following code snippet performs two unsequenced operations on i:
 *
 * 	int i = 5;
 * 	printf("Result = %d\n", i++ * i++);
 * You might think this code will produce the value 30, but because this code
 * has undefined behaviour, this outcome isn't guaranteed. Conservatively, we
 * can ensure that side effects have completed before the value is read by
 * placing every side-effecting operation in its own full expression. We can
 * rewrite this code as follows to eliminate the undefined behaviour.
 *
 * 	int i = 5;
 * 	int j = i++;
 * 	int k = i++;
 * 	printf("Result = %d\n", j * k);
 *
 * This code now contains a sequence point between every side-effecting
 * operation. However, it's impossible to tell whether this rewritten code
 * represent the original intent of the programmer, because the original code
 * had no defined meaning. If you choose to omit sequence points, you must be
 * sure you completely understand the sequencing of side effects. This same code
 * can also be written as follows without changing the behaviour:
 *
 * 	int i = 5;
 * 	int j = i++;
 * 	printf("Result = %d\n", j * i++);
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
  char abc[] = "abc";
  char xyz[] = "xyz";

  char *p = abc;
  printf("%c", ++*p);
  p = xyz;
  printf("%c", *p++);

  int nums[] = {0, 1, 2};
  int *ip = nums;
  int *op = nums;

  // printf("\n%d\n", *ip++);
  printf("%d\n", *(ip++));

  // printf("%d\n", ++*op);
  printf("%d\n", ++(*op));
  return 0;
}
