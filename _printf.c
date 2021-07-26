#include<stdio.h>
#include<stdarg.h>
#include "holberton.h"
/**
 * _printf - prints whatever character is given to it.
 * _printInt - prints integer using putchar
 * @n: inpt to _printInt function.
 * @format: the format type of the argument
 *
 * Return: numbeer of arguments passed to the function
 */
void _printInt(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n/10)
{
_printInt(n/10);
}
_putchar(n%10 + '0');
}

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
++n;
++format;
continue;
}
++format;
ctype = *format;
if (ctype == 'c')
{
c = va_arg(args, int);
_putchar(c);
++n;
++format;
}
else if (ctype == '%')
{
_putchar('%');
++n;
++format;
}
else if (ctype == 'd')
{
c = va_arg(args, int);
_printInt(c);
++n;
++format;
}
else if (ctype == 's')
{
s = va_arg(args, char *);
while (*s != '\0')
{
_putchar(*s);
++n;
++s;
}
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
