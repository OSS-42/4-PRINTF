/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/25 14:57:19 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
struct parameters
{
    unsigned char   flag;
    unsigned int    witdh;
    double          precision;
    unsigned char   lenght;
    unsigned char   converter;
} p;

static  ft_flags()
{
    if x = '-';
    if x = '0';
    if x = '#';
    if x = '+';
    if x = ' ';
}

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

static  ft_converter()
{
    if (x = c);
    if (x = s);
    if (x = p);
    if (x = i || d);
    if (x = u);
    if (x = x);
    if (x = X);
    if (x = %);    
}

ft_parameters()
{
    struct parameters p;
    p.flag = 0;
    p.witdh = 0;
    p.precision = 0;
    p.lenght = 0;
    p.converter = 0;
    
    if (s[1] = '-' || '0' || '#' || '+' || ' ')
        p.flag = 1;
    if (s[2] = 0-9) ==> ON/OFF
        p.witdh = 1;
    if (s[3&4] = .0-9) ==> ON/OFF
        p.precision = 1;
    if (s[5] = c/s/p/d/i/u/x/X/%) ==> ON/OFF
        p.converter = 1;
}

ft_paramend()
{
    
}

int printf(const char *format, ...)
{
    int             i;
    int             j;
    unsigned char   *paramstr;
    
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] = "%")
            j = 0;
            while(s[i + j] != '/0')
            {
                j++;
                if (ft_paramend(s[i + j]) == 1)
                    paramstr = ft_substr(s, i, j);
            }
        ft_strtrim (start : %, end : c/s/p/d/i/u/x/X/%)
        ft_parameters (s trimmé)
    }
}

int main()
{
    char    c = "S";
    char    s = "OSS 117 - Alerte Rouge en Afrique Noire !";
    int     i = 117;
    char    *p = s;
    
    
}