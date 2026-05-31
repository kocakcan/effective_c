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
 * */
