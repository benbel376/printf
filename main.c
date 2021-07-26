#include <limits.h>
#include <stdio.h>
#include "holberton.h"

int main(void)
{
  int n;
  n = _printf("Print %c %s\n", 'H', "Yes");
  _printf("printing String %s\n", "string");
  printf("%d", n);
  return (0);
}
