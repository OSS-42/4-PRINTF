/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:00:32 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/03 16:36:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_parameters
{
    va_list args;
    int     size;
    int     percentage;
    int     sign;
    int     square;
    int     space;
    int     plus;
} t_parameters;

int		ft_printf(const char *, ...);
void	ft_print_char(t_parameters *p);
void	ft_print_string(t_parameters *p, char *input, int pos);
void	ft_print_integer(t_parameters *p, char *input, int pos);

#endif