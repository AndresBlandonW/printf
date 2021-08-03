#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

int print_c(char ch);
int print_s(char *str);
int print_d(int n);
int print_u(unsigned int n);
int print_o(unsigned int n);

/**
 * _printf - print function
 * @format: type output
 * Return: 0
 */

int _printf(const char *format, ...)
{

char *str;
va_list pa;
unsigned int i, x;
int val;
unsigned int val2;
unsigned int size2 = 0;
unsigned int can_pa = 0;

for (x = 0; format[x] ; x++)
{
if (format[x] == '%')
{
can_pa++;
}
}

va_start(pa, format);
for (i = 0; format[i]; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == 'd')
{
val = va_arg(pa, int);
print_d(val);
i += 1;
}

if (format[i + 1] == 'i')
{
val = va_arg(pa, int);
print_d(val);
i += 1;
}

if (format[i + 1] == 'u')
{
val2 = va_arg(pa, unsigned int);
print_u(val2);
i += 1;
}

if (format[i + 1] == 'o')
{
val2 = va_arg(pa, unsigned int);
print_o(val2);
i += 1;
}

if (format[i + 1] == 'c')
{
char ch = (char)va_arg(pa, int);
print_c(ch);
i += 1;
}

if (format[i + 1] == 's')
{
str = va_arg(pa, char *);
print_s(str);
i += 1;
}
}
else
{
_putchar(format[i]);
}
}
va_end(pa);

return (0);
}


/**
 * print_d - unsigned number
 * @n: num to print
 * Return: data
 */
int print_d(int n)
{
int i, num, div, o, count = 0;

o = n % 10;
n = n / 10;
if (o < 0)
{
n = -n;
o = -o;
_putchar('-');
count++;
}
num = n;
div = 1;
if (num > 0)
{
while ((num / 10) != 0)
{
num = num / 10;
div = div * 10;
}
while (div >= 1)
{
i = n / div;
_putchar(i + '0');
count++;
n = n % div;
div = div / 10;
}
}
_putchar(o + '0');
count++;
return (count);
}

/**
* print_u - print decimal sin signo entero
* @n: data
* Return: data
*/

int print_u(unsigned int n)
{
unsigned int i, num, div, o, len = 0;

o = n % 10;
n = n / 10;
num = n;
div = 1;
if (num > 0)
{
while ((num / 10) != 0)
{
num = num / 10;
div = div * 10;
}
while (div >= 1)
{
i = n / div;
_putchar(i + '0');
len++;
n = n % div;
div = div / 10;
}
}
_putchar(o + '0');
len++;
return (len);
}

/**
* print_o - print octal convert
* @n: data
* Return: data
*/

int print_o(unsigned int n)
{
unsigned int a[11];
unsigned int i, m, sum;
int count;

m = 1073741824;
a[0] = n / m;
for (i = 1; i < 11; i++)
{
m /= 8;
a[i] = (n / m) % 8;
}
for (i = 0, sum = 0, count = 0; i < 11; i++)
{
sum += a[i];
if (sum || i == 10)
{
_putchar('0' + a[i]);
count++;
}
}
return (count);
}

/**
* print_s - print string
* @str: data
* Return: data
*/

int print_s(char *str)
{
int count;

if (str == NULL)
str = "(null)";
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
