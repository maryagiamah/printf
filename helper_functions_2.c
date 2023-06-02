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
    static char buffer[50];
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


int is_digit(char c)
{
        if (c >= '0' && c <= '9')
                return (1);

return (0);
}

int apply_width_precision_2(long long int, flags_t *f, int fld_wdth, int prec_sn, int no_ofchar)
{
        int dig_len = count_signed_digits(n);;
        int count = 0;
        int padding = ' ';

        if (prec_sn != -1 && prec_sn > len)
            count += print_padding('0', prec_sn - dig_len);
        else if (f->zero_flag == 1 && f->dash_flag != 1 && prec_sn == -1)
            padding = '0';

        no_ofchar += count;
        if (fld_wdth > no_ofchar  && f->dash_flag != 1)
        {
            count += print_padding(padding, fld_wdth - no_ofchar);
            print_number(n);
            return (count);
        }
        no_ofchar += count;
        if (fld_wdth > no_ofchar && f->dash_flag == 1)
            count += print_padding(padding, fld_wdth - no_ofchar);
        print_number(n);
        return (count);

}

