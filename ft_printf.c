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

#include "ft_printf.h"

static void	ft_conver_path(t_parameters *p, char *input, int pos)
{
	if (input[pos] == 'c')
		ft_print_char(p);
	if (input[pos] == 's')
		ft_print_string(p);
	if (input[pos] == 'd' || input[pos] == 'i')
		ft_print_integer(p);
	if (input[pos] == 'u')
		ft_print_uhextoa(p, 10, "0123456789");
	if (input[pos] == 'x')
		ft_print_uhextoa(p, 16, "0123456789abcdef");
	if (input[pos] == 'X')
	{
		p->hexcap = 1;
		ft_print_uhextoa(p, 16, "0123456789ABCDEF");
	}
	if (input[pos] == 'p')
		ft_print_ptoa(p, "0123456789abcdef");
}

static int	ft_isaconverter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_check_input(t_parameters *p, char *input, int pos)
{
	while (ft_isaconverter(input[pos]) != 1)
	{
		if (input[pos] == '#')
			p->square = 1;
		if (input[pos] == ' ')
		{
			if (p->plus == 1)
				p->space = 0;
			else
				p->space = 1;
		}
		if (input[pos] == '+')
		{
			p->plus = 1;
			p->space = 0;
		}
		pos++;
	}
	ft_conver_path(p, input, pos);
	return (pos);
}

int	ft_printf(const char *input, ...)
{
	int				i;
	int				len;
	t_parameters	*p;

	p = ft_calloc(sizeof(t_parameters), 1);
	va_start(p->args, input);
	i = -1;
	len = 0;
	while (input[++i])
	{
		if (input[i] == '%')
		{
			if (input[i + 1] == '%')
				p->size = p->size + write(1, "%", 1);
			i = ft_check_input(p, (char *)input, i + 1);
		}
		else
			len = len + write(1, &input[i], 1);
	}
	va_end(p->args);
	len = len + p->size;
	free(p);
	return (len);
}
