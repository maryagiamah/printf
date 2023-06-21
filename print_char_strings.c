#include "main.h"
#include <string.h>
#include <stddef.h>
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
        int i = 0;
        (void)m;

	if (s == NULL)
	{
		char *str  = "(null)";
		s = str;
		count = strlen(s);
	}
	if (prec_sn == 0)
	{
		char *ptr = "";
		s = ptr;
		count = 0;
	}
	if (prec_sn > 1  && prec_sn < count)
        {
		
		char str[20];
                while (i < prec_sn)
                {
			str[i] = s[i];
                        i++;
                }
		s[i] = '\0';
		s = str;
		count = prec_sn;
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
	int c, count = 1;
	c = va_arg(l, int);
        (void)m;
        (void)prec_sn;

	count += apply_char(c, f, fld_wdth, count); 
        return (count);
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

int apply_char(int c, flags_t *f, int fld_wdth, int no_ofchar)
{
	int count = 0;
        int padding = ' ';
	
	if (fld_wdth > no_ofchar  && f->dash_flag != 1 && f->zero_flag == 1)
	{
		count += print_padding(padding, fld_wdth - no_ofchar);
		_putchar(c);
		return (count);
	}
	if (fld_wdth > no_ofchar && f->dash_flag == 0  && f->zero_flag == 0)
        {
		count += print_padding(padding, fld_wdth - no_ofchar);
		_putchar(c);
                return (count);
        }
        if (fld_wdth > no_ofchar  && f->dash_flag == 1)
	{
		_putchar(c);
		count += print_padding(padding, fld_wdth - no_ofchar);
	}
	if (count == 0)
	{
		_putchar(c);
	}	
        return (count);

}
