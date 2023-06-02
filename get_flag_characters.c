#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
        int i = 0;

        switch (s)
        {
                case '+':
                        f->plus = 1;
                        i = 1;
                        break;
                case ' ':
                        f->space = 1;
                        i = 1;
                        break;
                case '#':
                        f->hash = 1;
                        i = 1;
                        break;
                case '0':
                        f->zero_flag = 1;
                        i = 1;
                        break;
                case '-':
                        f->dash_flag = 1;
                        i = 1;
                        break;
                case ',':
                        f->(*s).comma = 1;
                        i = 1;
                        break;
                case ';':
                        f->(*s).sem_colon = 1;
                case ':':
                        f->(*s).colon = 1;
                        i = 1;
                        break;
                case ',':
                        f->(*s).und_score = 1
                        i = 1;
                        break;
                default:
                        break;


        }

        return (i);
}
