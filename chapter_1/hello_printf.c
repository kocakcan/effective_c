#include <stdio.h>
#include <stdlib.h>

#define MESSAGE "Hello, world!\n"

int main(void) {
  int n = printf("%s", MESSAGE);
  if (n >= 0 && (size_t)n == sizeof(MESSAGE) - 1)
    return EXIT_SUCCESS;
  return EXIT_FAILURE;
}
