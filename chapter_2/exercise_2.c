#include <stdio.h>

double sum(double x, double y) { return x + y; }
double subtract(double x, double y) { return x - y; }
double multiply(double x, double y) { return x * y; }

static double (*afp[3])(double, double) = {sum, subtract, multiply};

int main(void) {
  double x = 2.71, y = 3.14;
  unsigned choice;

  printf("What's your choice?\n");
  scanf("%u", &choice);
  if (choice >= 0 && choice <= 2)
    printf("Result = %.2f\n", (*afp[choice])(x, y));
  else
    printf("Choice should be between 0-2\n");
  return 0;
}
