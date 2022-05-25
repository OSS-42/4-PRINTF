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

#include "ft_printf.h"

static int	ft_size_ptr(uintptr_t nb)
{
	int	count;

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
	uintptr_t	ptr;
	char		*add;
	int			len;

	ptr = va_arg(p->args, uintptr_t);
	if (!ptr)
	{
		p->size = p->size + write(1, "(nil)", 5);
		return ;
	}
	len = ft_size_ptr(ptr);
	add = ft_calloc(len + 1, 1);
	if (!add)
		return ;
	add[len] = '\0';
	p->size = p->size + write(1, "0x", 2) + len;
	while (len--)
	{
		add[len] = base[ptr % 16];
		ft_putstr_fd(add, 1);
		ptr = ptr / 16;
	}
	free(add);
}
