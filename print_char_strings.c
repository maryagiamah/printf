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
	int count = strlen(s);
	int len = strlen(s);
        int i = 0;
        (void)m;

	if (!s)
	{
		s = "(null)";
		count = strlen(s);
	}
	if (prec_sn > 1  && prec_sn < len)
        {
		
		char str[20];
			char *ptr = str;
                while (i < prec_sn)
                {
			*ptr++ = *(s + i);
                        i++;
                }
		*ptr = '\0';
                count = prec_sn;
		s = str;
        }	
	count += apply_str(s, f, fld_wdth, count);
return (count);
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
