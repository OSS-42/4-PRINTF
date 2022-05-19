/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:22:40 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/17 14:22:40 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
    unsigned int    n = 42;
    unsigned int    o = 0;
	unsigned long	p = 42;
	unsigned long	*test1 = &p;
    void *test2 = (void*)0xffffffffffffffff;
    int     q = 0;
    int     r = -1;
    int     t = 1;
    int     u = 2147483647;
 
    printf("-------CHAR------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%c|", c);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%c|", c);
    printf(" - %d\n", resultreal);
    printf("-------STRING------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%s|", s);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%s|", s);
    printf(" - %d\n", resultreal);
    printf("-------INT------\n");
    resultmine = ft_printf("Voici le resultat (mine): |%i|", i);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", i);
    printf(" - %d\n", resultreal);
    resultmine = ft_printf("Voici le resultat (mine): |%i|", q);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", q);
    printf(" - %d\n", resultreal);
    resultmine = ft_printf("Voici le resultat (mine): |%i|", r);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", r);
    printf(" - %d\n", resultreal);
    resultmine = ft_printf("Voici le resultat (mine): |%i|", t);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", t);
    printf(" - %d\n", resultreal);
    printf("-------SPACE-------\n");
    resultmine = ft_printf("Voici le resultat (mine): |% i|", j);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |% i|", j);
    printf(" - %d\n", resultreal);
    printf("--------SIGN-----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%+i|", j);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%+i|", j);
    printf(" - %d\n", resultreal);
    printf("--------INT_MIN & MAX-----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%i|", k);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", k);
    printf(" - %d\n", resultreal);
    resultmine = ft_printf("Voici le resultat (mine): |%i|", u);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%i|", u);
    printf(" - %d\n", resultreal);
    printf("-------UINT_MAX----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%u|", l);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%u|", l);
    printf(" - %d\n", resultreal);
    printf("-------HEXAMIN----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%x|", m);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%x|", m);
    printf(" - %d\n", resultreal);  
    printf("-------HEXACAP----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%X|", m);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%X|", m);
    printf(" - %d\n", resultreal);
    printf("-------INT TO HEXA----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%x|", n);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%x|", n);
    printf(" - %d\n", resultreal);
    resultmine = ft_printf("Voici le resultat (mine): |%x|", l);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%x|", l);
    printf(" - %d\n", resultreal);
    printf("-------DASH HEXA----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%#x|", n);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%#x|", n);
    printf(" - %d\n", resultreal);   
    resultmine = ft_printf("Voici le resultat (mine): |%#x|", o);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%#x|", o);
    printf(" - %d\n", resultreal);
	printf("-------POINTER----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%p|", test1);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%p|", test1);
    printf(" - %d\n", resultreal);  
    resultmine = ft_printf("Voici le resultat (mine): |%p|", test2);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%p|", test2);
    printf(" - %d\n", resultreal);  
    printf("-------PERCENT----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%%|");
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%%|");
    printf(" - %d\n", resultreal);  
    printf("-------MULTIPLE----\n");
    resultmine = ft_printf("Voici le resultat (mine): |%d%%|", n);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%d%%|", n);
    printf(" - %d\n", resultreal);  
    resultmine = ft_printf("Voici le resultat (mine): |%s%d|", s, n);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%s%d|", s, n);
    printf(" - %d\n", resultreal);  
    printf("-------UB Test----\n");
    resultmine = ft_printf("Voici le resultat (mine): |% +d|", n);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |% +d|", n);
    printf(" - %d\n", resultreal);  
    resultmine = ft_printf("Voici le resultat (mine): |%#s|", s);
    printf(" - %d\n", resultmine);
    resultreal = printf("Voici le resultat (real): |%#s|", s);
    printf(" - %d\n", resultreal);  
    return (0);
}
