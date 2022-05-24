/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:00:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/16 12:07:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_parameters
{
	va_list	args;
	int		size;
	int		percentage;
	int		neg;
	int		hexcap;
	int		square;
	int		space;
	int		plus;
}	t_parameters;

int		ft_printf(const char *input, ...);
void	ft_print_char(t_parameters *p);
void	ft_print_string(t_parameters *p);
void	ft_print_integer(t_parameters *p);
void	ft_print_unsigned(t_parameters *p);
void	ft_print_uhextoa(t_parameters *p, int divider, char *base);
void	ft_print_ptoa(t_parameters *p, char *base);

#endif