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

#include "../libprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lred "\033[1;91m"
#define lgreen "\033[1;92m"
#define lyellow "\033[1;93m"
#define lmagenta "\033[1;95m"
#define lcyan "\033[1;96m"
#define default "\033[1;0m"
#define tick "\xE2\x9C\x93"
#define cross "\xE2\x9D\x8C"

#define TITLE(title) print_title(title)
#define TEST_NAME(test_name) print_test(test_name)
#define VS print_vs()

static void print_title(char* title) 
{
	printf("%s\n", lmagenta);
	printf("\t----- %s -----", title);
	printf("%s\n\n", default);
}

static void print_test(char* test_name) 
{
	printf("%s\n", lcyan);
	printf("----- %s -----", test_name);
	printf("%s\n", default);
}

static void	print_result(int resultmine, int resultreal)
{
	if (resultmine == resultreal)
	{
		printf("%s", lgreen);
		printf(" - %s", tick);
		printf("%s\n", default);
	}
	else
	{
		printf("%s", lred);
		printf(" - %s", cross);
		printf("%s\n", default);
	}
}

static void print_vs()
{
	printf("%s", lyellow);
	printf(" vs ");
	printf("%s", default);
}

int main() 
{
	int					resultmine = 0;
	int					resultreal = 0;
	char				c = 'S';
	char				s[] = "! OSS 117 !";
	char				w[] = "";
	int					i = -42;
	int					j = 42;
	int					k = -2147483648;
	unsigned int		l = 4294967295;
	unsigned int		m = 0xfafa;
	unsigned int		n = 42;
	unsigned int		o = 0;
	unsigned long		p = 42;
	unsigned long		*test1 = &p;
	void 				*test2 = (void*)0xffffffffffffffff;
	int					q = 0;
	int					r = -1;
	int					t = 1;
	int					u = 2147483647;
	unsigned long long  v = UINT64_MAX;
	char				x[] = "QC";
	
	TITLE("Obligatoire");

	TEST_NAME("CHAR");
	resultmine = ft_printf("YOUR PRINTF : |%c|", c);
	print_vs();
	resultreal = printf("THE PRINTF : |%c| ", c);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("STRING");
	resultmine = ft_printf("YOUR PRINTF : |%s|", s);
	print_vs();
	resultreal = printf("THE PRINTF : |%s| ", s);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%s|", w);
	print_vs();
	resultreal = printf("THE PRINTF : |%s| ", w);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("INT");
	resultmine = ft_printf("YOUR PRINTF : |%d|", i);
	print_vs();
	resultreal = printf("THE PRINTF : |%d| ", i);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%d|", q);
	print_vs();
	resultreal = printf("THE PRINTF : |%d| ", q);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%d|", r);
	print_vs();
	resultreal = printf("THE PRINTF : |%d| ", r);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%d|", t);
	print_vs();
	resultreal = printf("THE PRINTF : |%d| ", t);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("INT_MIN & MAX");
	resultmine = ft_printf("YOUR PRINTF : |%i|", k);
	print_vs();
	resultreal = printf("THE PRINTF : |%i| ", k);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%i|", u);
	print_vs();
	resultreal = printf("THE PRINTF : |%i| ", u);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("UINT_MAX");
	resultmine = ft_printf("YOUR PRINTF : |%u|", l);
	print_vs();
	resultreal = printf("THE PRINTF : |%u| ", l);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("HEXAMIN");
	resultmine = ft_printf("YOUR PRINTF : |%x|", m);
	print_vs();
	resultreal = printf("THE PRINTF : |%x| ", m);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal); 

	TEST_NAME("HEXACAP");
	resultmine = ft_printf("YOUR PRINTF : |%X|", m);
	print_vs();
	resultreal = printf("THE PRINTF : |%X| ", m);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("INT TO HEXA");
	resultmine = ft_printf("YOUR PRINTF : |%x|", n);
	print_vs();
	resultreal = printf("THE PRINTF : |%x| ", n);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%x|", l);
	print_vs();
	resultreal = printf("THE PRINTF : |%x| ", l);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("POINTER");
	resultmine = ft_printf("YOUR PRINTF : |%p|", test1);
	print_vs();
	resultreal = printf("THE PRINTF : |%p| ", test1);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%p|", test2);
	print_vs();
	resultreal = printf("THE PRINTF : |%p| ", test2);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("PERCENT");
	resultmine = ft_printf("YOUR PRINTF : |%%|");
	print_vs();
	resultreal = printf("THE PRINTF : |%%| ");
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("MULTIPLE");
	resultmine = ft_printf("YOUR PRINTF : |%d%%|", n);
	print_vs();
	resultreal = printf("THE PRINTF : |%d%%| ", n);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%d%s|", n, x);
	print_vs();
	resultreal = printf("THE PRINTF : |%d%s| ", n, x);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TITLE("Bonus 2");

	TEST_NAME("DASH HEXA");
	resultmine = ft_printf("YOUR PRINTF : |%#x|", n);
	print_vs();
	resultreal = printf("THE PRINTF : |%#x| ", n);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	resultmine = ft_printf("YOUR PRINTF : |%#X|", o);
	print_vs();
	resultreal = printf("THE PRINTF : |%#X| ", o);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);

	TEST_NAME("SPACE");
	resultmine = ft_printf("YOUR PRINTF : |% i|", j);
	print_vs();
	resultreal = printf("THE PRINTF : |% i| ", j);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
	
	TEST_NAME("SIGN");
	resultmine = ft_printf("YOUR PRINTF : |%+i|", j);
	print_vs();
	resultreal = printf("THE PRINTF : |%+i| ", j);
	printf(" %d <-> %d", resultmine, resultreal);
	print_result(resultmine, resultreal);
   
	return (0);
}
