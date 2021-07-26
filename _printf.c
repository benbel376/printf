#include<stdio.h>
#include<stdarg.h>
#include "holberton.h"
/**
 * _printf - prints whatever character is given to it.
 * @format: the format type of the argument
 *
 * Return: numbeer of arguments passed to the function
 */

int _printf(const char *format, ...)
{
int n, c;
char *s, ctype;
va_list args;
va_start(args, format);

n = 0;
while (*format != '\0')
{
if (*format != '%')
{
_putchar(*format);
++format;
continue;
}
++format;
ctype = *format;
if (ctype == 'c')
{
c = va_arg(args, int);
_putchar(c);
++format;
}
else if (ctype == 's')
{
s = va_arg(args, char *);
while (*s != '\0')
{
_putchar(*s);
++s;
}
++format;
}
++n;
}
_putchar('\n');
va_end(args);
return (n);
}
