#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>

/**
* _printf - printf function
* @format: type of output
* Return: length
*/

int _printf(const char *format, ...)
{

va_list pa;
int i, len = 0;
int ispa = 0;

if (format == NULL)
return (0);

va_start(pa, format);
for (i = 0; *(format + i) != '\0'; i++)
{
if (format[i] == '%')
{
ispa = 1;
}
else if (ispa == 1)
{
ispa = 0;
if (format[i] == 'c')
{
print_c(va_arg(pa, int));
len += 1;
}
else if (format[i] == 's')
{
len += print_s(va_arg(pa, char *));
}
else if (format[i] == '%')
{
_putchar('%');
len += 1;
}
else if (format[i + 1] == 'd')
{
len += print_d((long)(va_arg(pa, int)));
}
else if (format[i + 1] == 'i')
{
len += print_d((long)(va_arg(pa, int)));
}
else
{
_putchar('%');
_putchar(format[i]);
len += 2;
}

}
else
{
_putchar(format[i]);
len++;
}
}
va_end(pa);

return (len);
}


/**
* print_d - unsigned number
* @n: num to print
* Return: data
*/
int print_d(long int n)
{
int len = 0;

if (n < 0)
{
_putchar('-');
len += 1;
n = -n;
}

if (n / 10)
len += print_d(n / 10);

_putchar(n % 10 + '0');
len += 1;

return (len);
}


/**
* print_s - print string
* @str: data
* Return: data
*/

int print_s(char *str)
{
int len = 0;

if (str != NULL)
while (*str)
{
_putchar(*str++);
len += 1;
}
else
return (print_s("(null)"));
return (len);
}

/**
* print_c - print character
* @ch: data
* Return: data
*/

int print_c(char ch)
{
_putchar(ch);
}
