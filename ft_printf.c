/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/26 12:01:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h> //pour fonction variadique

/* Vous devez gérer les conversions suivantes : cspdiuxX%

Each conversion specification is introduced by the character %, and ends with a conversion
specifier.  In between there may be (in this order) zero or more flags, 
an optional minimum field width, an optional precision and an optional length modifier.

The overall syntax of a conversion specification is:

    %[flags][width][.precision][length]converter
           
Bonus : FLAG '-' : left-justify within the given field width. Right justification is the default.
Bonus : FLAG '0' : left-pads the number with 0 instead of spaces, where padding is specified.
Bonus : FLAG '#' : used with o, x or X. Make the value preceded by 0, 0x or 0X for values different of 0.
Bonus : FLAG ' ' : if no sign is going to be written, a blank space is inserted before the value.
Bonus : FLAG '+' : Forces to precede the result with a plus or minus sign. By default only neg.

Witdh : (number) : minimum number to be printed. If the value is to be printed is shorter than this number, result padded with blank spaces.
                    value is not truncated even if the result is larger.

Bonus : PRECISION '.' : (number) : for (d, i, o , u, x, X) - specifies minimum numbers of digits to be written.
                                    If the value to be written is shorter than this number, the result is padded with leading zeros.
                                    The value is not truncated even if the result is longer. 
                                    A precision of 0 means that no character is written for the value 0.
                                    When no precision is specified, the default is 1. 
                                    If the period is specified without an explicit value for precision, 0 is assumed.

/* Lenght 'h' : interpreted as short int or unsigned short int (only for i, d, o, u, x and X).
/* Lenght 'l' : interpreted as long int or unsigned long int (for i, d, o , u, x and X) wide character or wide char string for c and s.
/* Lenght 'L' : interpreted as long double (only for e, E, f, g and G).  

Conversion 'c' : Char
Conversion 's' : string of char
Conversion 'p' : pointer address
Conversion 'd/i' : signed decimal integer
Conversion 'u' : unsigned decimal integer
Conversion 'x' : unsigned hexadecimal integer
Conversion 'X' : unsigned hexadecimal integer (capital letters)
Conversion '%' : character '%'.

return number of characters written. On failure, negative number is return.
*/

typedef struct s_parameters
{
    va_list args;
    int     witdh;
    int     precision;
    int     zero_pad;
    int     dot;
    int     force_sign;
    int     dash;
    int     square;
    int     size;
    int     sign;
    int     is_zero;
    int     percentage;
    int     space_pad;
} t_parameters;

static ft_witdh()
{
    x = size limiter;
}

static  ft_precision()
{
    if (x = NULL)
        default = 1;
    if (x = 0)
        no char written for 0;
    if (x = ".")
        go x = 0;
    if (result < x)
        missing spots = 0;
}

static void ft_conver_path(t_print *p, char *format, int pos)
{
    if (format[pos] == 'c')
        ft_print_char(p);
    if (format[pos] == 's')
        ft_print_string(p);
    if (format[pos] == 'd' || format[pos] == 'i')
        ft_print_integer(p);
    if (format[pos] == 'u')
        ft_print_unsigned(p);
    if (format[pos] == 'x')
        ft_print_hexamin(p);
    if (format[pos] == 'X')
        ft_print_hexacap(p);
    if (format[pos] == '%')
        ft_print_perc(p);
}

static int  ft_isaconverter(char c)
{
    if (c == "c" || c == "s" || c == "p" || c == "i" || c == "d"
        || c == "u" || c == "x" || c == "X" || c == "%")
        return (1);
    return (0);
}

static int  ft_flag_check(t_print *p, char *format, int pos)
{
    while (format)
    {
        while (ft_isaconverter(format[pos]) != 1)
        {
            if (format[pos] == '.')
            {
                if (ft_isdigit(format[pos + 1] != 1)
                    p->dot = 1;
                    p->precision = format[pos + 1];
                if ()
                p->dot = 2;
                pos++;
            }
            if (format[pos] == '-')
            {
                p->dash = 1;
                p->zero.pad = 0;
                pos++;
            }
            if (format[pos] == '#')
            {
                p->square = 1;
                pos++;
            }
            if (format[pos] == '0' && p.dash == 0 && p.precision == 0)
            {
                p->zero.pad = 1;
                pos++;
            }
            if (format[pos] == ' ')
            {
                p->space_pad = 1;
                pos++;
            }
            if (format[pos] == '+')
            {
                p->force_sign = 1;
                p->space_pad = 0;
                pos++;
            }
            if (ft_isaconverter(format[pos]) == 1)
                ft_conver_path(p, format, pos);
            return (-1);
        }
    }
}

t_parameters *ft_param_init(t_print *p)
{
    //tab = ft_calloc(13, 1);
    p.witdh = 0;
    p.precision = 0;
    p.zero_pad = 0;
    p.dot = 0;
    p.force_sign = 0;
    p.dash = 0;
    p.square = 0;
    p.size = 0;
    p.sign = 0;
    p.is_zero = 0;
    p.percentage = 0;
    p.space_pad = 0;
    return (p);
}

int printf(const char *format, ...)
{
    int             i;
    int             result;
    t_parameters    *p;
    
    p = (t_parameters *)malloc(sizeof(t_parameters));
    if (!p)
        return (-1);
    ft_param_init(tab);
    va_start(p->args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            i = ft_flag_check(p, format, i + 1);
        else
            result = result + write(1, &format[i], 1);
    }
    va_end(p->args);
    result = result+p->size;
    free(p);
    return(result);
}    

int main()
{
    char    c = "S";
    char    s = "OSS 117 - Alerte Rouge en Afrique Noire !";
    int     i = 117;
    char    *p = s;    
}
