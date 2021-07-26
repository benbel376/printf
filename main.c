#include <limits.h>
#include <stdio.h>
#include "holberton.h"

int main(void)
{
  int n;
  n = _printf("Print %c %s\n", 'H', "Yes");
  _printf("printing String %s %d\n", "string", 34);
  printf("%d", n);
  return (0);
}
