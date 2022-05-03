/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:00:05 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/03 16:35:43 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_print_char(t_parameters *p)
{
	char a;

	a = va_args(p->args, int);
	
	
}

void	ft_print_string(t_parameters *p, char *input, int pos)
{
	while (input[pos])
	{
		write(1, va_args(p->args, input), 1);
		p->size += 1;
		pos++;
	}
}

void	ft_print_integer(t_parameters *p, char *input, int pos)
{
	
}