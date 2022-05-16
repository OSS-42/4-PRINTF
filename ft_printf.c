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
    /*if (input[pos] == 'u')
        ft_print_unsigned(p);
    if (input[pos] == 'x')
        ft_print_hexamin(p);
    if (input[pos] == 'X')
        ft_print_hexacap(p);
    if (input[pos] == '%')
        ft_print_perc(p);*/
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
    while (ft_isaconverter(input[pos] != 1))
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

/*t_parameters *ft_param_init(t_parameters *p)
{
    //p = ft_calloc(6, 1);
    p->size = 0;
    p->sign = 0;
    p->square = 0;
    p->percentage = 0;
    p->space = 0;
    p->plus = 0;
    //return (p);
}*/

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
    char    *p = s;
    
    c = '5';    
    resultmine = ft_printf("Voici le resultat (mine): | %+i |\n", i);
    printf("result (mine) : %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): | %+i |\n", i);
    printf("result (real) : %d\n", resultreal);
    return (0);
}
