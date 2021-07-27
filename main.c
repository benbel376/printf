#include <limits.h>
#include <stdio.h>
#include "holberton.h"

int main(void)
{
  int n = _printf("print this %s %c %% %F\n", "ddIfo", 'K');
  printf("%d\n", n);

  return (0);
}
