#include<stdio.h>
#include<stdarg.h>
#include "holberton.h"
/**
 * _chPrinter - prints whatever character is given to it.
 * @format: pointer to pointer of format.
 * @c: character input
 * @n: count input
 *
 * Return: numbeer of arguments passed to the function
 */

int _chPrinter(const char **format, char c, int n)
{
int nIn = n + 1;
_putchar(c);
++*format;
return (nIn);
}
/**
 * _stPrinter - prints string;
 * @format: pointer to pointer of format.
 * @s: accepts string pointer
 * @n: accepts count number
 *
 * Return: number of count of character
 */
int _stPrinter(const char **format, char *s, int n)
{
int nIn = n;
while (*s != '\0')
{
_putchar(*s);
++nIn;
++s;
}
++*format;
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
if (format == NULL)
{
return (-1);
}
while (*format != '\0')
{
if (*format != '%')
{
n = _chPrinter(&format, *format, n);
continue;
}
++format;
ctype = *format;
if (ctype == 'c')
{
c = va_arg(args, int);
n = _chPrinter(&format, c, n);
}
else if (ctype == '%')
{
n = _chPrinter(&format, '%', n);
}
else if (ctype == 's')
{
s = va_arg(args, char *);
n = _stPrinter(&format, s, n);
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
