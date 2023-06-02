#include "main.h"
/**
 * print_padding - prints padding characters
 * @c: the character to print
 * @n: the number of times to print the character
 *
 * Return: number of characters printed
 */
int print_padding(char c, int n)
{
        int count = 0;

        for (int i = 0; i < n; i++)
                count += _putchar(c);

        return count;
}
/**
 * count_signed_digits - counts the number of digits in a signed decimal number
 * @n: the signed decimal number
 * Return: the number of digits
 */
int count_signed_digits(long int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

/**
 * count_unsigned_digits - counts the number of digits in an unsigned decimal number
 * @n: the unsigned decimal number
 * Return: the number of digits
 */
int count_unsigned_digits(unsigned long int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}
/**
 * print_number - helper function that loops through
 * an integer and prints all its digits using recursion.
 * @n: integer to be printed
 */
void print_number(long int n)
{
	unsigned long int n1;
        if (n < 0) /* if n is less than zero , it coverted to positve numer but the sign is printed */
        {
                n1 *= -n;
                _putchar('-');
        }

        if (n1 / 10) /*base case for recursive call to check if the number is not  zero when divided by ten */
                print_number(n1 / 10);

        _putchar ((n1 % 10) + '0');
}
int apply_width_precision(char *str, flags_t *f, int fld_wdth, int prec_sn, int  no_ofchar)
{
        int len = _strlen(str);
        int count = 0;
        int padding = ' ';

        if (prec_sn != -1 && prec_sn > len)
            count += print_padding('0', prec_sn - len);
        else if (f->zero_flag == 1 && f->dash_flag != 1 && prec_sn == -1)
            padding = '0';

        no_ofchar += count;
        if (fld_wdth > no_ofchar  && f->dash_flag != 1 && f->zero_flag == 1)
	{
            count += print_padding(padding, fld_wdth - no_ofchar);
		_puts(str);
        	return (count);
	}
	if (fld_wdth > no_ofchar  && f->dash_flag != 1 && f->zero_flag == 0)
        {
            count += print_padding(padding, fld_wdth - no_ofchar);
		_puts(str);
                return (count);
        }
        no_ofchar += count;
        if (fld_wdth > no_ofchar  && f->dash_flag == 1)
            count += print_padding(padding, fld_wdth - no_ofchar);
	_puts(str);
        return (count);
}
