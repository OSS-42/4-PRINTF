/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/03 16:28:00 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static void ft_conver_path(t_parameters *p, char *input, int pos)
{
    if (input[pos] == 'c')
        ft_print_char(p);
    if (input[pos] == 's')
        ft_print_string(p, input, pos);
    if (input[pos] == 'd' || input[pos] == 'i')
        ft_print_integer(p);
    if (input[pos] == 'u')
        ft_print_unsigned(p);
    if (input[pos] == 'x')
        ft_print_hexamin(p);
    if (input[pos] == 'X')
        ft_print_hexacap(p);
    if (input[pos] == '%')
        ft_print_perc(p);
}

static int  ft_isaconverter(char c)
{
    if (c == "c" || c == "s" || c == "p" || c == "i" || c == "d"
        || c == "u" || c == "x" || c == "X" || c == "%")
        return (1);
    return (0);
}

static int ft_check_input (t_parameters *p, char *input, int pos)
{
    while(ft_isaconverter(input[pos] != 1))
    {
        if (input[pos] == '#')
        {
            p->square = 1;
            pos++;
        }
        if (input[pos] == ' ')
        {
            p->space = 1;
            pos++;
        }
        if (input[pos] == '+')
        {
            p->plus = 1;
            pos++;
        }
        else    
            ft_conver_path(p, input, pos);
    }
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
        return (NULL);
    p = (t_parameters *)malloc(sizeof(t_parameters));
    if (!p)
        return (-1);
    //ft_param_init(p);
    p = ft_calloc(6, 1);
    va_start(p->args,input);
    i = -1;
    len = 0;
    while (input[++i])
    {
        if (input[i] == '%')
            i = ft_check_input(p, input, i + 1);
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
    char    c = "S";
    char    s = "OSS 117 - Alerte Rouge en Afrique Noire !";
    int     i = 117;
    char    *p = s;    
    ft_printf("Voici le resultat :% s\n", s);
    printf("Voici le resultat :% s\n", s);
    return (0);
}
