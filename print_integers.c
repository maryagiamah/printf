#include "main.h"
/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_int(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
    int long n;

    if (m->l == 1)
        n = va_arg(l, long int);
    else if (m->h == 1)
        n = (short int) va_arg(l, int);
    else if (m->hh == 1)
        n = (signed char) va_arg(l, int);
    else
        n = va_arg(l, int);

    int res = count_signed_digits(n);
    int dig_len = res;
	if (n < 0)
		res += 1;

    if (prec_sn == 0)
    {
	print_number(n = 0);
        return 1;
    }
    if (f->space == 1 && f->plus == 0 && n >= 0)
        res += _putchar(' ');
    else if (f->plus == 1 && n >= 0)
        res += _putchar('+');
    res += apply_width_precision_2(n, f, fld_wdth, pre_csn, res);
    return (res);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_unsigned(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
    unsigned long int u;

    if (m->l == 1)
        u = va_arg(l, unsigned long int);
    else if (m->h == 1)
        u = (unsigned short int) va_arg(l, unsigned int);
    else if (m->hh == 1)
        u = (unsigned char) va_arg(l, unsigned int);
    else
        u = va_arg(l, unsigned int);

    int res = count_unsigned_digits(u);
    char *str = convert(u, 10,1)

    if (pre_csn == 0)
    {
	n = 0;
	return 1;
    }
    if (f->plus == 1 && f-> space == 0)
            res += _putchar('+');
    else if (f->space == 1)
            res  += _putchar(' ');
    res += apply_width_precision(str , f,  fld_wdth, prec_sn, res);
    return (res);
}
