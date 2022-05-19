/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:50 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/19 14:11:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_size_ptr(uintptr_t nb)
{
	long	count;

	count = 1;
	while (nb / 16 > 0)
	{
		nb = nb / 16;
		count ++;
	}
	return (count);
}

void	ft_print_ptoa(t_parameters *p, char *base)
{
	uintptr_t	i;
	char		*j;
	int			len;

	i = va_arg(p->args, uintptr_t);
	len = ft_size_ptr(i);
	j = (char *)malloc(sizeof(char) * len + 1);
	if (!j)
		return ;
	j[len] = '\0';
	p->size = p->size + write(1, "0x", 2) + len;
	while (len--)
	{
		j[len] = base[i % 16];
		ft_putstr_fd(j, 1);
		i = i / 16;
	}
	free(j);
}
