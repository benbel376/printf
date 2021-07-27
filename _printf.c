#include<stdio.h>
#include<stdarg.h>
#include "holberton.h"
/**
 * _chPrinter - prints whatever character is given to it.
 *
 * @c: character input
 * @n: count input
 *
 * Return: numbeer of arguments passed to the function
 */

int _chPrinter(char c, int n)
{
int nIn = n + 1;
_putchar(c);
return (nIn);
}
/**
 * _stPrinter - prints string;
 * @s: accepts string pointer
 * @n: accepts count number
 *
 * Return: number of count of character
 */
int _stPrinter(char *s, int n)
{
int nIn = n;
while (*s != '\0')
{
_putchar(*s);
++nIn;
++s;
}
return (nIn);
}
/**
 * _printf - prints input data;
 *
 * @format: format of input
 *
 * Return: number of characters printed
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
n = _chPrinter(*format, n);
++format;
continue;
}
++format;
ctype = *format;
if (ctype == 'c')
{
c = va_arg(args, int);
n = _chPrinter(c, n);
++format;
}
else if (ctype == '%')
{
n = _chPrinter('%', n);
++format;
}
else if (ctype == 's')
{
s = va_arg(args, char *);
n = _stPrinter(s, n);
++format;
}
else
{
_putchar('%');
++n;
}
}
va_end(args);
return (n);
}
