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
 */
#include <stdio.h>
#include <string.h>

struct sigrecord {
  int signum;
  char signame[20];
  char sigdesc[100];
} sigline, *sigline_p;

void func(int arr[5]) { printf("%d\n", arr[0]); }

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
  return 0;
}
