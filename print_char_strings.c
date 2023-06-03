#include "main.h"
#include <string.h>

/**
 * print_string - prints a string
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the len_mod struct that contains length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_string (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        char *s = va_arg(l, char *);
        char *ptr = s;
        int str_len = strlen(s);
        int i = 0;
	(void)f;
        (void)m;
        (void)fld_wdth;

        if (prec_sn >= 0 && prec_sn < str_len && s)
        {
                while (i < prec_sn && *ptr != '\0')
                {
                        _putchar(*ptr++);
                        i++;
                }
                return prec_sn;
        }
	if (!s)
                s = "(null)";

        return (_puts(s));
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the len_mod struct that contains length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_char (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
	int c;
        (void)f;
        (void)m;
        (void)fld_wdth;
        (void)prec_sn;
	c = va_arg(l, int);
	if (!c)
		return (0);
        _putchar(c);
        return (1);
}

/**
 * print_n - stores the number of characters printed so far
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the len_mod struct that contains length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_n (va_list l, int count)
{
        int *ptr = va_arg(l, int *);

        *ptr = count;
        return (0);
}
