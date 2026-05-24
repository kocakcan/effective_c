#include <stdio.h>

static unsigned counter = 0;

void increment(void) { ++counter; }
unsigned retrieve(void) { return counter; }

int main(void) {
  for (int i = 0; i < 5; ++i) {
    increment();
    printf("%d\n", retrieve());
  }
  return 0;
}
