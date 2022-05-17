/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/16 12:14:58 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_conver_path(t_parameters *p, char *input, int pos)
{
    if (input[pos] == 'c')
        ft_print_char(p);    
    if (input[pos] == 's')
        ft_print_string(p);
    if (input[pos] == 'd' || input[pos] == 'i')
        ft_print_integer(p);
    if (input[pos] == 'u')
        ft_print_unsigned(p);
    if (input[pos] == 'x')
        ft_print_hexa(p, 16, "0123456789abcdef");
    if (input[pos] == 'X')
        ft_print_hexa(p, 16, "0123456789ABCDEF");
    /*if (input[pos] == '%')
        ft_print_perc(p);
    if (input[pos] == 'p')
        ft_print_hexa(p, 16, "0123456789abcdef"*/
    //return (pos);
}

static int  ft_isaconverter(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd'
        || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    return (0);
}

static int ft_check_input (t_parameters *p, char *input, int pos)
{
    while (ft_isaconverter(input[pos]) != 1)
    {
        if (input[pos] == '#')
        {
            p->square = 1;
            pos++;                                          
        }
        if (input[pos] == ' ')
        {
            if  (p->plus == 1)
                p->space = 0;
            else
                p->space = p->space + 1;
            pos++;
        }
        if (input[pos] == '+')
        {
            p->plus = 1;
            p->space = 0;
            pos++;
        }    
    }
    ft_conver_path(p, input, pos);
    return (pos);
}

int ft_printf(const char *input, ...)
{
    int             i;
    int             len;
    t_parameters    *p;

    if (input == NULL)
        return (0);
    p = ft_calloc(sizeof(t_parameters), 1);
    va_start(p->args, input);
    i = -1;
    len = 0;
    while (input[++i])
    {
        if (input[i] == '%')
            i = ft_check_input(p, (char *)input, i + 1);
        else
            len = len + write(1, &input[i], 1);          
    }
    va_end(p->args);
    len  = len + p->size;
    free(p);
    return(len);
}

int main()
{
    int     resultmine;
    int     resultreal;
    char    c;
    char    s[] = "OSS 117 - Alerte Rouge en Afrique Noire !";
    int     i = -42;
    int     j = 42;
    int     k = -2147483648;
    unsigned int    l = 4294967295;
    unsigned int    m = 0xfafa;
    char    *p = s;
    
    c = 'S';    
    printf("-------CHAR------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%c|\n", c);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%c|\n", c);
    printf("result (real) : %d\n", resultreal);
    printf("-------STRING------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%s|\n", s);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%s|\n", s);
    printf("result (real) : %d\n", resultreal);
    printf("-------INT------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%i|\n", i);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|\n", i);
    printf("result (real) : %d\n", resultreal);
    printf("-------SPACE-------\n");
    resultmine = ft_printf("Voici le resultat (mine): |% i|\n", j);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |% i|\n", j);
    printf("result (real) : %d\n", resultreal);
    printf("--------SIGN-----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%+i|\n", j);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%+i|\n", j);
    printf("result (real) : %d\n", resultreal);
    printf("--------INT_MIN-----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%i|\n", k);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|\n", k);
    printf("result (real) : %d\n", resultreal);
    printf("-------UINT_MAX----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%u|\n", l);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%u|\n", l);
    printf("result (real) : %d\n", resultreal);
    printf("-------HEXAMIN----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%u|\n", l);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%u|\n", l);
    printf("result (real) : %d\n", resultreal);    
    printf("-------HEXACAP----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%u|\n", l);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%u|\n", l);
    printf("result (real) : %d\n", resultreal);
    return (0);
}
