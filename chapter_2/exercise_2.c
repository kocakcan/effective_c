#include <stdio.h>

double sum(double x, double y) { return x + y; }
double subtract(double x, double y) { return x - y; }
double multiply(double x, double y) { return x * y; }

static double (*afp[3])(double, double) = {sum, subtract, multiply};

int main(void) {
  char choice;
  double x, y;
  printf("x = ? \n");
  scanf(" %lf", &x);
  printf("y = ? \n");
  scanf(" %lf", &y);

  do {
    printf("a. Sum\n");
    printf("b. Subtract\n");
    printf("c. Multiply\n");
    printf("> Quit (press 'q' or 'Q')\n");
    printf("What's your choice?\n");
    scanf(" %c", &choice);

    switch (choice) {
    case 'a':
    case 'A':
      printf("Result of the sum = %.2f\n", (*afp[0])(x, y));
      break;
    case 'b':
    case 'B':
      printf("Result of the subtraction = %.2f\n", (*afp[1])(x, y));
      break;
    case 'c':
    case 'C':
      printf("Result of the multiplication = %.2f\n", (*afp[2])(x, y));
      break;
    case 'q':
    case 'Q':
      printf("See you!\n");
      break;
    default:
      printf("error: unknown argument %c\n", choice);
      break;
    }
  } while (choice != 'q' && choice != 'Q');
  return 0;
}
