#include "holberton.h"
#include <stdio.h>

/**
* _printf - printf function
* @format: type of output
* Return: length
*/

int _printf(const char *format, ...)
{

char *str;
va_list pa;
unsigned int len, i;

va_start(pa, format);
for (i = 0; *(format + i) != '\0'; i++)
{
if (format[i] == '%')
{
len += 1;
if (format[i + 1] == 'c')
{
char ch = (char)va_arg(pa, int);
len += print_c(ch);
i += 1;
}
else if (format[i + 1] == 's')
{
str = va_arg(pa, char *);
len += print_s(str);
i += 1;
}
else if (format[i + 1] == 'd')
{
len += print_d((long)(va_arg(pa, int)));
i += 1;
}
else if (format[i + 1] == 'i')
{
len += print_d((long)(va_arg(pa, int)));
i += 1;
}
else if (format[i + 1] == '%')
{
_putchar('%');
len += 1;
i += 1;
}
else
{
_putchar('%');
_putchar(format[i + 1]);
len += 2;
i += 1;
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
int count = 0;

if (str == NULL)
str = "(null)";
else
for (count = 0; str[count]; count++)
{
_putchar(str[count]);
}
return (count);
}

/**
* print_c - print character
* @ch: data
* Return: data
*/

int print_c(char ch)
{
_putchar(ch);
return (1);
}
