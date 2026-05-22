/***
 * Objects, Functions, Types, and Pointers
 *
 * Every type in C is either an object type or a function type.
 *
 * An object is storage in which you can represent values. To be precise, an
 * object is defined by the C Standard as a "region of data storage in the
 * execution environment, the contents of which can represent values," with the
 * added note, "when referenced, an object can be interpreted as having a
 * particular type." A variable is an example of an object.
 *
 * Variables have a declared type that tells you the kind of object its value
 * represe- nts. For example, an object with type int contains an integer value.
 * The type is im- portant because the collection of bits that represent one
 * type of object will likely have a different value if interpreted as a
 * different type of object. For example, t- he number 1 is represented in IEEE
 * 754 by the bit pattern 0x3f800000 but if you were to interpret this same bit
 * pattern as an integer, you'd get the value 1,065,353,216 instead of 1.
 *
 * Functions are not objects but do have types. A function type is characterized
 * by bo- th its return type as well as the number and types of bits parameters.
 *
 * The C language also has pointers, which can be thought of as an address--a
 * location in memory where an object or function is stored. A pointer type is
 * derived from the referenced type T is called a pointer to T.
 *
 * Because objects and functions are different things, object pointers and
 * function po- inters are also different thing, and should not be used
 * interchangeably.
 *
 * Declaring Variables
 *
 * When you declare a variable, you assign it a type and provide it a name, or
 * identif- ier, by which to reference the variable. Listing 2-1 declares two
 * integer objects with initial values. This simple program also declares, but
 * doesn't define, a swap function to swap those values.
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
 * This example program shows a main function with a single code block between
 * the { } characters. This kind of code block is also known as a compound
 * statement. We defi- ne two variables, a and b, within the main function. We
 * declare the variables as ha- ving the type int and initialize them to 21 and
 * 17, respectively. Each variable must have a declaration. The main function
 * then calls the swap function to try to swap the values of the two integers.
 * The swap function is declared in this program, but not defined.
 *
 * Declaring Multiple Variables
 *
 * You can declare multiple variables in any single declaration, but doing so
 * can get confusing if the variables are pointers or arrays, or the variables
 * are different types. For example, the following declarations are all correct:
 *
 * 	char *src, c;
 * 	int x, y[5];
 * 	int m[12], n[15][3], o[21];
 * The first line declares two variables, src and c, which have differen types.
 * The src variable has a type of char *, and c has a type of char. The second
 * line again decl- ares two variables, x and y, with different types. The
 * variable x has a type int, a- nd y is an array of five elements of type int.
 * The third line declares three arrays
 * --m, n, and o--with different dimensions and numbers of elements. These
 * declarations are easier to understand if each is on its own line: char *src;
 *	// src has a type of char * char c;		// c has a type of char
 * 	int x;		// x has a type of int
 * 	int y[5];	// y is an array of 5 elements of type int
 * 	int m[12];	// m is an array of 12 elements of type int
 * 	int n[15][13]	// n is an array of 15 arrays of 3 elements of type int
 * 	int o[21];	// o is an array of 21 elements of type int
 * Readable and understandable code is less likely to have defects.
 *
 * Swapping Values (First Attempt)
 *
 * Each object has a storage duration that determines its lifetime, which is the
 * time during program execution for which the object exists, has storage, has a
 * constant add- ress, and retains its last-stored value. Objects must not be
 * referenced outside their lifetime.
 *
 * Local variables such as a and b from Listing 2-1 have automatic storage
 * duraiton, me-aning that they exist until execution leaves the block in which
 * they're defined. We are going to attempt to swap the values stored in these
 * two variables. Listing 2-2 is our first attempt to implement the swap
 * function.
 *
 * 	void swap(int a, int b) {
 *		int t = a;
 *		a = b;
 *		b = t;
 *		printf("swap: a = %d, b = %d\n", a, b);
 *	}
 *	Listing 2-2: The swap function
 * The swap function declares two parameters, a and b, that you use to pass
 * arguments to this function. C distinguishes between parameters, which are
 * objects declared as part of the function declaration that acquire a value on
 * entry to the function, and argum- ents, which are comma-separated expressions
 * you include in the function call express- ion. We also declare a temporary
 * variable t of type int in the swap function and init ialize it to the value
 * of a. This variable is used to temporarily save the value sto- red in a so
 * that it is not lost during the swap.
 *
 * The variables a and b were initialized to 21 and 17, respectively. The first
 * call to printf within the swap function shows these two values swapped, but
 * the second call to printf in main shows the original values unchanged.
 *
 * C is a call-by-value (also called pass-by-value) language, which means that
 * when you provide an argument to a function, the value of that argument is
 * copied into a disti- nct variable for use within the function. The swap
 * function assigns the values of the objects you pass as arguments to the
 * respective parameters. When the values of the pa rameters in the function are
 * changed, the values in the caller are unaffected because they are distinct
 * objects. Consequently, the variables a and b retain their original values in
 * main during the second call to printf. The goal of the program was to swap
 * the values of these two objects. By testing the program, we've discovered it
 * has a bug, or defect.
 *
 * Swapping Values (Second Attempt)
 *
 * To repair this bug, you can use pointers to rewrite the swap function. We use
 * the ind irection (*) operator to both declare pointers and dereference them,
 * as shown in List ing 2-3.
 *
 * 	void swap(int *pa, int *pb) {
 *		int t = *pa;
 *		*pa = *pb;
 *		*pb = t;
 *		return;
 *	}
 *	Listing 2-3: The revised swap function using pointers
 * When used in a function declaration or definition, * acts part of a pointer
 * declarato r indicating that the parameter is a pointer to an object or
 * function of a specific t ype. In the rewritten swap function, we specify two
 * parameters, pa and pb, and declar e them both as type pointers to int. When
 * you use the unary * operator in expressions within the function, the unary
 * * operator dereferences the pointer to the object. For example, consider the
 * followin g assignment:
 *
 * 	pa = pb;
 * This replaces the value of the pointer pa with the value of the pointer pb.
 * Now consi der the actual assignment in the swap function:
 *
 * 	*pa = *pb;
 * This dereferences the pointer pb, reads the referenced value, dereferences
 * the pointe r pa, then overrides the value at the location referenced by pa
 * with the value refere nced by pb. When you call the swap function in main,
 * you must also place an ampersand (&) c character before each variable name:
 *
 * 	swap(&a, &b);
 * The unary & is the address-of operator, which generates a pointer to its
 * operand. Thi s change is necessary because the swap function now accepts
 * pointers to objects of ty pe int as parameters instead of simply values of
 * type int.
 *
 * Scope
 *
 * Objects, functions, macros and other C language identifiers have scope that
 * delimits the contiguous region where they can be accessed. C has four types
 * of scope: file, b lock, function prototype, and function.
 *
 * 	The scope of an object or function identifier is determined by where it
 * is decl ared. If the declaration is outside any block or parameter list, the
 * identifier has f ile scope, meaning the scope is the entire text file in
 * which it appears as well as a ny files included after that point. If the
 * declaration appears inside a block or within the list of parameters, it has
 * block scope, meaning that the identifier it declares is accessbile only
 * within th e block. The identifiers for a and b from Listing 2-4 have block
 * scope and can be use d to refer to only these variables within the code block
 * in the main function in whic h they're defined. If the declaration appears
 * within the list of parameter declarations in a funct ion prototype (not part
 * of a function definition), the identifier has function protot ype scope,
 * which terminates at the end of the function declarator. Function scope is the
 * area between the opening { of a function definition and its closing }. A
 * label n ame is the only kind of identifier that has function scope. Labels
 * are identifiers f ollowed by a colon and identify a statement in a function
 * to which control may be tr ansferred. Scopes can be nested, with inner and
 * outer scopes. For example, you can have a block scope inside another block
 * scope, and every block scope is defined within a fi le scope. The inner scope
 * has access to the outer scope, but not vice versa. As the n ame implies, any
 * inner scope must be completely contained within the outer scopes th at
 * encompass it. If you declare the same identifier in both the inner scope and
 * an outer scope, the identifier declared in the outer scope is hidden by the
 * identifier within the in ner scope, which takes precedence. In this case,
 * naming the identifier will refer to the object in the inner scope; the object
 * from the outer scope is hidden and cannot be referenced by its name. The
 * easiest way to prevent this from becoming a problem i s to use different
 * names. Listing 2-5 demonstrates different scopes and how identifi ers
 * declared in inner scopes can hide identifiers declared in outer scopes.
 *
 * 	int j;			// file scope of j begins
 *
 * 	void f(int i) {		// block scope of i begins
 *		int j = 1;	// block scope of j begins; hides file-scope j
 *		i++;		// i refers to the function parameter
 *		for (int i = 0; i < 2; i++) {	// block scope of loop-local i
 * begins int j = 2;	// block scope of inner j begins; hides outer j
 *			printf("%d\n", j);	// inner j is in scope, prints 2
 *		}
 *		printf("%d\n", j);	// the outer j is in scope, prints 1
 *	}	// the block scope of i and j ends
 *
 *	void g(int j);	// j has function prototype scope, hides file-scope j
 *	Listing 2-5: Scope
 * 	There is nothing wrong with this code, provided the comments accurately
 * descri be your intent. Best practices is to use different names for different
 * identifiers t o avoid confusion, which leads to bugs. Using short names such
 * as i and j is fine fo r identifiers with small scopes. Identifiers in large
 * scopes should have longer, des criptive names that are unlikely to be hidden
 * in nested scopes. Some compilers will warn about hidden identifiers.
 *
 * Storage Duration
 *
 * Objects have a storage duration that determines their lifetime. Altogether,
 * four sto rage duration are available: automatic, static, thread, and
 * allocated. Objects of au tomatic storage duration are declared within a block
 * or as a function parameter. The lifetime of these objects begins when the
 * block in which they're declared begins exe cution, and ends when execution of
 * the block ends. If the block is entered recursive ly, a new object is created
 * each time, each with its own storage.
 *
 * NOTE: Scope and lifetime are entirely different concepts. Scope applies to
 * identifie rs, whereas lifetime applies to objects. The scope of an identifier
 * is the code regi on where the object denoted by the identifier can be
 * accessed by its name. The lifet ime of an object is the time period for which
 * the object exists.
 *
 * 	Objects declared in file scope have static storage duration. The
 * lifetime of t hese objects is the entire execution of the program, and their
 * stored value is initi alized prior to program startup. You can also declare a
 * variable within a block scop e to have static storage duration using the
 * storage-class specifier static, as shown in the counting example in Listing
 * 2-6. These objects persist after the function has exited.
 *
 * 	void increment(void) {
 *		static unsigned int counter = 0;
 *		counter++;
 *		printf("%d\n", counter);
 *	}
 *
 *	int main(void) {
 *		for (int i = 0; i < 5; i++) {
 *			increment();
 *		}
 *		return 0;
 *	}
 *	Listing 2-6: A counting example
 * 	This program outputs 1 2 3 4 5. We initialize the static variable
 * counter to 0 once at program startup, and increment it each time the
 * increment function is called . The lifetime of counter is the entire
 * execution of the program, and it will retain its last-stored value throughout
 * its lifetime. You could achieve the same behaviour by declaring counter with
 * file scope. However, it is good software engineering pract ice to limit the
 * scope of an object wherever possible. Static objects must be initialized with
 * a constant value and not a variable: int *func(int i) { const int j = i;
 *	// ok static int k = j;	// error return &k;
 *	}
 * A constant value refers to literal constants (for example, 1, 'a', 0xFF),
 * enum membe rs, and the results of operators such as alignof or sizeof; not
 * const-qualified obje cts.
 *
 * Alignment
 *
 * Object types have alignment requirements that place restrictions on the
 * addresses at which objects of that type may be allocated. An alignment
 * represents the number of b ytes between successive addresses at which a given
 * object can be allocated. CPUs may have different behaviour when accessing
 * aligned data (for example, the data address is a multiple of the data size)
 * versus unaligned data. Some machine instructions can perform multiple
 * accesses on non-word boundaries , but there may be a performance penalty. A
 * word is a natural, fixed-size unit of a data handled by the instruction set
 * or the hardware of the processor. Some platforms cannot access unaligned
 * memory. Alignment requirements may depend on the CPU word si ze (typically,
 * 16, 32, or 64 bits). Generally, C programmers need not concern themselves
 * with alignment requiremen ts, because the compiler chooses suitable
 * alignments for its various types. Dynamica lly allocated memory from malloc
 * is required to be sufficiently aligned for all stan dard types, including
 * arrays and structures. However, on rare occasions, you might n eed to
 * override the compiler's default choices; for example, to align data on the bo
 * undaries of the memory cache lines that must start at power-of-two address
 * boundarie s, or to meet other system-specific requirements. Traditionally,
 * these requirements were met by linker commands, or by overallocating memory
 * with malloc followed by rou nding the user address upward, or similar
 * operations involving other nonstandard fac ilties. C11 introduced a simple,
 * forward-compatible mechanism for specifying alignment s. Alignments are
 * represented as values of type size_t. Every valid alignment value is a
 * nonnegative integral power of two. An object type imposes a default alignment
 * requirement on every object of that type: a stricter alignment (a larger
 * power of tw o) can be requested using the alignment specifier (_Alignas). You
 * can include an ali gnment specifier in the declaration specifiers of a
 * declaration. Listing 2-7 uses th e alignment specifier to ensure that
 * good_buff is properly aligned (bad_buff) may ha ve incorrect alignment for
 * member-access expressions).
 *
 * 	struct S {
 *		int i;
 *		double d;
 *		char c;
 *	};
 *
 *	int main(void) {
 *		unsigned char bad_buff[sizeof(struct S)];
 *		_Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
 *
 *		struct S *bad_s_ptr = (struct S *)bad_buff; // wrong pointer
 * alignment struct S *good_s_ptr = (struct S *)good_buff; // correct pointer
 * alig.
 *	}
 *	Listing 2-7: Use of the _Alignas keyword
 * 	Alignments are ordered from weaker to stronger (also called stricter)
 * alignmen ts. Stricter alignments have larger alignment values. And address
 * that satisfies an alignment requirement also satisfies any valid, weaker
 * alignment requirement.
 */
#include <stdio.h>

struct S {
  int i;
  double d;
  char c;
};

void swap(int *pa, int *pb) { // pa -> a: 21	pb -> b: 17
  int t = *pa;                // t: 21
  *pa = *pb;                  // pa -> a: 17	pb -> b: 21
  *pb = t;                    // pa -> a: 17	pb -> b: 21
  return;
}

int main(void) {
  int a = 21; // a: 21
  int b = 17; // b: 17
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b); // a: 17	b: 21
  unsigned char bad_buff[sizeof(struct S)];
  _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

  struct S *bad_s_ptr = (struct S *)bad_buff;
  struct S *good_s_ptr = (struct S *)good_buff;
  return 0;
}
