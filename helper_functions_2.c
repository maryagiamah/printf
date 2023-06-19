#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static  char buffer[50];
	char *ptr;

	rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
        	*--ptr = rep[num % base];
        	num /= base;
	} while (num != 0);
    return ptr;
}


int is_digit(char  c)
{
        if (c >= '0' && c <= '9')
                return (1);

	return (0);
}

int apply_width_precision_2 (long int n, flags_t *f, int fld_wdth, int prec_sn, int no_ofchar)
{
        int dig_len = count_signed_digits(n);
        int count = 0;
        int padding = ' ';

	if (prec_sn > 0)
		f->zero_flag = 0;
	if (prec_sn > 1 && prec_sn > dig_len)
		count += print_padding('0', prec_sn - dig_len);

	if (f->zero_flag == 1 && f->dash_flag != 1 && prec_sn > 0)
		padding = '0';

        no_ofchar += count;
        if (fld_wdth > no_ofchar && f->dash_flag == 0 && f->zero_flag == 1)
        {
            count += print_padding(padding, fld_wdth - no_ofchar);
            print_number(n);
            return (count);
        }
	else if (fld_wdth > no_ofchar && f->dash_flag == 0  && f->zero_flag == 0)
	{
		count += print_padding(' ', fld_wdth - no_ofchar);
		print_number(n);
		return (count);
	}
        if (fld_wdth > no_ofchar && f->dash_flag == 1)
	{
		print_number(n);
		count += print_padding(padding, fld_wdth - no_ofchar);
	}
	if (count == 0)
		print_number(n);
        return (count);
}


/**
 * Initialize flags and mod_f variables.
 */
void initialize_variables(flags_t *flags, len_mod *mod_f)
{
    flags->plus = 0;
    flags->space = 0;
    flags->hash = 0;
    flags->zero_flag = 0;
    flags->dash_flag = 0;

    mod_f->h = 0;
    mod_f->l = 0;
    mod_f->hh = 0;
    mod_f->j = 0;
    mod_f->z = 0;
    mod_f->t = 0;
}

int _strlen (char *s)
{
	char *ptr = s;
	int i = 0;
	while (*ptr)
	{
		i++;
		ptr++;

	}
	return (i);


}
apply_width_precision_3 (char *str, flags_t *f, int fld_wdth, int no_ofchar)
{
	int len = _strlen(str);
        int count = 0;
        int padding = ' ';
	char *ptr = s;
        int str_len = _strlen(s);
        int i = 0;
	
	if (prec_sn > 1  && prec_sn < len)
        {
                while (i < prec_sn && *ptr != '\0')
                {
                        _putchar(*ptr);
                        i++;
                }
                no_ofchar = prec_sn;
        }
	if (fld_wdth > no_ofchar  && f->dash_flag != 1 && f->zero_flag == 1)
	{
		count += print_padding(padding, fld_wdth - no_ofchar);
		_puts(str);
		return (count);
	}
	if (fld_wdth > no_ofchar && f->dash_flag == 0  && f->zero_flag == 0)
        {
		count += print_padding(padding, fld_wdth - no_ofchar);
		_puts(str);
                return (count);
        }
        if (fld_wdth > no_ofchar  && f->dash_flag == 1)
	{
		_puts(str);
		count += print_padding(padding, fld_wdth - no_ofchar);
	}
	if (count == 0)
	{
		_puts(str);
	}	
        return (count);

}
