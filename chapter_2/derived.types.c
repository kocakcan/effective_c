/***
 * Derived Types
 *
 * Derived types are types that are constructed from other types. These include
 * pointers, arrays, type definitions, structures, and unions. Pointer Types
 *
 * Pointer Types
 *
 * A pointer type is derived from the function or object type that it points to,
 * called the referenced type. A pointer provides a reference to an entity of
 * the referenced type.
 *    The following three declarations declare a pointer to int, a pointer to
 * char, and a pointer to void:
 *
 *    int *ip;
 *    char *cp;
 *    void *vp;
 *
 *    Earlier in the chapter, I introduced the address-of (&) and indirection
 * (*) operators. You use the & operator to take the address of an object or
 * function. If the object is an int, for example, the result of the operator
 * has the type pointer to int:
 *
 *    int i = 17;
 *    int *ip = &i;
 *
 *    We declare the variable ip as a pointer to int and assign it the address
 * of i. You can also use the & operator on the result of the * operator:
 *
 *    ip = &*ip;
 *
 *    Dereferencing ip by using the indirection operator resolves to the actual
 * object i. Taking the address of *ip by using the & operator retrieves the
 * pointer, so these two operation cancel each other out.
 *    The unary * operator converts a pointer to a type into a value of that
 * type. It denotes indirection and operates only on pointers. If the operand
 * points to a function, the result of using the * operator is the function
 * designator, and if it points to an object, the result is a value of the
 * designated object. For example, if the operand is a pointer to int, the
 * result of the indirection operator has the type int. If the pointer is not
 * pointing to a valid object or function, bad things may happen.
 *
 * Arrays
 *
 * An array is a contiguously allocated sequence of objects that all have the
 * same element type. Array types are characterized by their element types and
 * the number of elements in the array. Here we declare an array of 11 elements
 * of type int identified by ia, and an array of 17 elements of type pointer to
 * float identified by afp:
 *
 *    int ia[11];
 *    float *afp[17];
 *
 *    You use square brackets ([]) to identify an element of an array. For
 * example, the following contrived code snippet creates the string "0123456789"
 * to demonstrate how to assign values to the element of an array:
 *
 *    char str[11];
 *    for (unsigned int i = 0; i < 10; i++)
 *      str[i] = '0' + i;
 *    str[10] = '\0';
 *
 *    The first line declares an array of char with a bound of 11. This
 * allocates sufficient storage to create a string with 10 characters plus a
 * null character. The for loop iterates 10 items, with the values of i ranging
 * from 0 to 9. Each iteration assigns the result of the expression '0' + i to
 * str[i]. Following the end of the loop, the null character is copied to the
 * final element of the array str[10].
 *    In the expression at 1, str is automatically converted to a pointer to the
 * first member of the array (an object of type char), and i has an unsigned
 * integer type. The subscript ([]) operator and addition (+) operator are
 * defined so that str[i] is identical to *(str + i). When str is an array
 * object (as it is here), the expression str[i] designates the ith element of
 * the array (counting from 0). Because arrays are indexed starting at 0, the
 * array char str[11] is indexed from 0 to 10, with 10 being the last element,
 * as referenced on the last line of this example.
 *    If the operand of the unary & operator is the result of a [] operator, the
 * result is as if the & operator were removed and the [] operator were changed
 * to a + operator. For example &str[10] is the same as str + 10.
 *    You can also declare multidimensional arrays. Listing 2-8 declares arr in
 * the function main as a two-dimensional 5 x 3 array of type int, also referred
 * to as a matrix.
 *
 *    void func(int arr[5]);
 *    int main(void) {
 *      unsigned int i = 0;
 *      unsigned int j = 0;
 *      int arr[3][5];
 *      func(arr[i]);         -> 1
 *      int x = arr[i][j];    -> 2
 *      return 0;
 *    }
 *    Listing 2-8: Matrix operations
 *
 *    More precisely, arr is an array of three elements, each of which is an
 * array of five elements of type int. When you use the expression arr[i] at 1
 * (which is equivalent to *(arr + i)), the following occurs:
 *
 *    1. arr is converted to pointer to the initial array of five elements of
 * type int starting at arr[i].
 *    2. i is scaled to the type of arr by multiplying i by the size of one
 * array of five int objects.
 *    3. The results from steps 1 and 2 are added.
 *    4. Indirection is applied to the result to produce an array of five
 * elements of type int.
 *
 *    When used in the expression arr[i][j] at 2, that array is converted to a
 * pointer to the first element of type int, so arr[i][j] produces an object of
 * type int.
 *
 *                                Type Definitions
 *
 * You use a typedef to declare an alias for existing type; it never creates a
 * new type. For example, each of the following declarations creates a new type
 * alias:
 *
 * typedef unsigned int uint_type;
 * typedef signed char schar_type, *schar_p (*fp)(void);
 *
 *    On the first line, we declare uint_type as an alias for the type unsigned
 * int. On the second line, we declare schar_type as an alias for signed char,
 * schar_p as an alias for signed char *, and fp as an alias for signed char
 * (*)(void). Identifiers that end int _t in the standard headers are type
 * definitions (aliases for existing types). Generally speaking, you should not
 * follow this convention in your own code because C Standard reserves
 * identifiers that match the patterns int[0-9a-z_]*_t and uint[0-9a-z_]*_t, and
 * the Portable Operating System Interface (POSIX) reserves all identifiers that
 * end in _t. If you define identifiers that use these names, they may collide
 * with names used by the implementation, which can cause problems that are
 * difficult to debug.
 *
 * Structures
 *
 * A structure type (also known as a struct) contains sequentially allocated
 * member objects. Each object has its own name and may have a distinct
 * type--unlike arrays, which must all be of the same type. Structures are
 * similar to record types found in other programming languages. Listing 2-9
 * declares an object identified by sigline that has a type of struct sigrecord
 * and a pointer to the sigline object identified by sigline_p.
 *
 *    struct sigrecord {
 *      int signum;
 *      char signame[20];
 *      char sigdesc[100];
 *    } sigline, *sigline_p;
 *    Listing 2-9: struct sigrecord
 *
 *    The structure has three member objects: signum is an object of type int,
 * signame is an array of type char consisting of 20 elements, and sigdesc is an
 * array of type char consisting of 100 elements.
 *    Structures are useful for declaring collections of related objects and may
 * be used to represent things such as a date, customer, or personnel record.
 * They are especially useful for grouping objects that are frequently passed
 * together as arguments to a function, so you don't need to repeatedly pass
 * individual objects separately.
 *    Once you have defined a structure, you'll likely want to reference its
 * members. You reference members of an object of the structure type by using
 * the structure member (.) operator. If you have a pointer to a structure, you
 * can reference its members with the structure pointer (->) operator. Listing
 * 2-10 demonstrates the use of each operator.
 *
 *    sigline.signum = 5;
 *    strcpy(sigline.signame, "SIGINT");
 *    strcpy(sigline.sigdesc, "Interrupt from keyboard");
 *
 *    sigline_p = &sigline;   -> 1
 *
 *    sigline_p->signum = 5;
 *    strcpy(sigline_p->signame, "SIGINT");
 *    strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
 *    Listing 2-10: Referencing structure members
 *
 *    The first three lines of Listing 2-10 directly access members of the
 * sigline object by using the . operator. At 1, we assign the pointer to
 * sigline_p to the address of the sigline object. In the final three lines of
 * the program, we indirectly access the members of the sigline object by using
 * the -> operator through the sigline_p pointer.
 *
 * Unions
 *
 * Union types are similar to structures, except that the memory used by the
 * member objects overlaps. Unions can contain an object of one type at one
 * time, and an object of a different type at a different time, but never both
 * objects at the same time, and are primarily used to save memory. Listing 2-11
 * shows the union u that contains three structures: n, ni, and nf. This union
 * might be used in a tree, graph, or other data structure that has some nodes
 * that contain integer values (ni) and other nodes that containing
 * floating-point values (nf).
 *
 *    union {
 *      struct {
 *        int type;
 *      } n;
 *      struct {
 *        int type;
 *        int intnode;
 *      } ni;
 *      struct {
 *        int type;
 *        double doublenode;
 *      } nf;
 *    } u;
 *    u.nf.type = 1;
 *    u.nf.doublenode = 3.14;
 *    Listing 2-11: Unions
 *
 *    As with structures, you can access union members via the . operator. Using
 * a pointer to a union, you can reference its members with the -> operator. In
 * Listing 2-11, the type member in the nf struct of the union is referenced as
 * u.nf.type, and the doublenode member is referenced as u.nf.doublenode. Code
 * that uses this union will typically check the type of the node by examining
 * the value stored in u.n.type and then accessing either the intnode or
 * doublenode struct depending on the type. If this had been implemented as a
 * structure, each node would contain storage for both the intnode and the
 * doublenode members. The use of a union allows the same storage to be used for
 * both members.
 *
 * Tags
 *
 * Tags are special naming mechanism for structs, unions, and enumerations. For
 * example, the identifier s appearing in the following structure is a tag:
 *
 *    struct s {
 *      // --snip--
 *    };
 * By itself, a tag is not a type name and cannot be used to declare a variable.
 * Instead, you must declare variables of this type as follows:
 *
 * struct s v;  // instance of struct s
 * struct s *p  // pointer to struct s
 *    The names of unions and enumerations are also tags and not types, meaning
 * that they cannot be used alone to declare a variable. For example:
 *
 * enum day { sun, mon, tue, wed, thu, fri, sat };
 * day today;         // error
 * enum day tomorrow; // OK
 *    The tags of structures, unions, and enumerations are defined in a separate
 * namespace from ordinary identifiers. This allows a C program to have both a
 * tag and another identifier with the same spelling in the same scope:
 *
 * enum status { ok, fail };  // enumeration
 * enums status status(void); // function
 *
 * You can even declare an object s of type struct s:
 *
 * struct s s;
 * This may not be good practice, but it is valid in C. You can think of struct
 * tags as type names and define an alias for the tag by using a typedef. Here's
 * an example:
 *
 * typedef struct s { int x; } t;
 * This now allows you to declare variables of type t instead of struct s. The
 * tag name in struct, union, and enum is optional, so you can just dispense
 * with it entirely:
 *
 * typedef struct { int x; } t;
 *    This works fine except in the case of self-referential structures that
 * contain pointers to themselves:
 *    struct tnode {
 *      int count;
 *      struct tnode *left;
 *      struct tnode *right;
 *    };
 * If you omit the tag on the first line, the compiler may complain because the
 * referenced structure on lines 3 and 4 has not yet been declared, or because
 * the whole structure is not used anywhere. Consequently, you have no choice
 * but to declare a tag for the structure, but you can declare a typedef as
 * well:
 *
 *  typedef struct tnode {
 *    int count;
 *    struct tnode *left;
 *    struct tnode *right;
 *  } tnode;
 *
 *    Most C programmers use a different name for the tag and the typedef, but
 * the same name works just fine. You can also define this type before the
 * structure so that you can use it to declare the left and right members that
 * refer to other objects of type tnode:
 *
 * typedef struct tnode tnode;
 * struct tnode {
 *    int count;
 *    tnode *left;
 *    tnode *right;
 * } tnode;
 *
 *    Type definitions can improve code readability beyond their use with
 * structures. For example, all three of the following declarations of the
 * signal function specify the same type:
 *
 * typedef void fv(int), (*pfv)(int);
 * void (*signal(int, void (*)(int)))(int);
 * fv *signal(int, fv *);
 * pfv signal(int, pfv);
 *
 * Type Qualifiers
 *
 * All the types examined so far have been unqualified types. Types can be
 * qualified by using one or more of the following qualifiers: const, volatile,
 * and restrict. Each of these qualifiers changes behaviours when accessing
 * objects of the qualified type.
 *    The qualified and unqualified versions of types can be used
 * interchangeably as arguments to functios, return values from functions, and
 * members of unions.
 *
 * Note: The _Atomic type qualifier supports concurrent programs.
 *
 * const
 *
 * Objects declared with the const qualifier (const-qualified types) are not
 * modifiable. In particular, they're not assignable but can have constant
 * initializers. This means objects with const-qualified types can be placed in
 * read-only memory by the compiler, and any attempt to write to them will
 * result in a runtime error:
 *
 * const int i = 1; // const-qualified int
 * i = 2;           // error: i is const-qualified
 *
 *    It's possible to accidentally convince your compiler to change a
 * const-qualified object for you. In the following example, we take the address
 * of a const-qualified object i and tell the compiler that this is actually a
 * pointer an to int:
 *
 * const int i = 1; // object of const-qualified type
 * int *ip = (int *)&i;
 * *ip = 2;         // undefined behaviour
 *
 *    C does not allow you to cast away the const if the original was declared
 * as a const-qualified object. This code might appear to work, but it's
 * defective and may fail later. For example, the compiler might place the
 * const-qualified object in read-only memory, causing a memory fault when
 * trying to store a value in the object at runtime.
 *    C allows you to modify an object that is pointer to by a const-qualified
 * pointer by casting the const away, provided that the original object was not
 * declared const.
 *
 * int i = 12;
 * const int j = 12;
 * const int *ip = &i;
 * const int *jp = &j;
 * *(int *)ip = 42;    // ok
 * *(int *)jp = 42;    // undefined behaviour
 *
 * volatile
 *
 * Objects of volatile-qualified types serve a special purpose. Static
 * volatile-qualified objects are used to model memory-mapped input/output
 * (I/O) ports, and static constant volatile-qualified objects model
 * memory-mapped input ports such as a real-time clock.
 *    The values stored in these objects may change without the knowledge of the
 * compiler. For example, every time the value from a real-time clock is read,
 * it may change, even if the value has not been written by the C program.
 * Using a volatile-qualified type lets the compiler know that the value may
 * change, and ensures that every access to the real-time clock occurs
 * (otherwise, an access to the real-time clock may be optimized away or
 * replaced by a previously read and cached value). In the following code, for
 * example, the compiler must generate instructions to read the value from port
 * and then write this value back to port:
 *
 * volatile int port;
 * port = port;
 *
 *    Without the volatile qualification, the compiler would see this as a no-op
 * (a programming statement that does nothing) and potentially eliminate both
 * the read and the write.
 *    Also, volatile-qualified types are used for communications with signal
 * handlers and with setjmp/longjmp. Unlike in Java and other programming
 * languages, volatile-qualified types in C should not be used for
 * synchronization between threads.
 *
 * restrict
 *
 * A restrict-qualified pointer is used to promote optimization. Objects
 * indirectly accessed through a pointer frequently cannot be fully optimized
 * because of potential aliasing, which occurs more than one pointer refers to
 * the same object. Aliasing can inhibit optimizations, because the compiler
 * can't tell if portions of an object can change values when another apparently
 * unrelated object is modified, for example.
 *    The following function copies n bytes from the storage referenced by q to
 * the storage referenced by p. The function parameters p and q are both
 * restrict-qualified pointers:
 *
 * void f(unsigned int n, int * restrict p, int * restrict q) {
 *    while (n-- > 0) {
 *       *p++ = *q++;
 *    }
 * }
 *
 *    Because both p and q are restrict-qualified pointesr, the compiler can
 * assume that an object accessed through one of the pointer parameters is not
 * also accessed through the other. The compiler can make this assessment based
 * solely on the parameter declarations without analyzing the function body.
 * Although using restrict-qualified pointers can result in more efficient code,
 * you must ensure that the pointers do not refer to overlapping memory to
 * prevent undefined behaviour.
 */
#include <stdio.h>
#include <string.h>

struct sigrecord {
  int signum;
  char signame[20];
  char sigdesc[100];
} sigline, *sigline_p;

void func(int arr[5]) { printf("%d\n", arr[0]); }

void f(unsigned int n, char *restrict p, char *restrict q) {
  while (n-- > 0)
    *p++ = *q++;
}

int main(void) {
  unsigned int i = 0;
  unsigned int j = 0;
  int arr[3][5] = {
      {30, 1, 2, 3, 4},
      {2, 4, 6, 8, 10},
      {1, 3, 5, 7, 9},
  };
  func(arr[i + 1]);
  int x = arr[i][j];
  printf("%d\n", x);

  sigline.signum = 5;
  strcpy(sigline.signame, "SIGINT");
  strcpy(sigline.sigdesc, "Interrupt from keyboard");

  sigline_p = &sigline;

  sigline_p->signum = 5;
  strcpy(sigline_p->signame, "SIGINT");
  strcpy(sigline_p->sigdesc, "Interrupt from keyboard");

  int k = 12;
  const int l = 12;
  const int *ip = &k;
  const int *jp = &l;
  *(int *)ip = 42; // ok since k is not const-qualified
  // If the compiler store l in read-only memory this would crash the program
  *(int *)jp = 42; // UB: l is const-qualified
  char buf[1024];
  char *best_boss = "Knight Artorias";
  f(strlen(best_boss), buf, best_boss);
  printf("Best boss in DS1 is %s\n", buf);
  return 0;
}
