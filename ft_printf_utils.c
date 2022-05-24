/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:00:05 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/16 12:18:28 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(long nb, int divider)
{
	unsigned long	count;

	count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb / divider > 0)
	{
		nb = nb / divider;
		count++;
	}
	return (count);
}

void	ft_print_char(t_parameters *p)
{
	char	c;

	c = (char) va_arg(p->args, int);
	p->size = p->size + write(1, &c, 1);
}

void	ft_print_string(t_parameters *p)
{
	char	*s;
	int		i;

	s = va_arg(p->args, char *);
	if (!s)
	{
		p->size = p->size + write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i])
	{
		p->size = p->size + write(1, &s[i], 1);
		i++;
	}
}

void	ft_print_integer(t_parameters *p)
{
	long	i;

	i = va_arg(p->args, int);
	if (i < 0)
	{
		p->neg = 1;
		p->space = 0;
	}
	if (p->plus == 1 && p->neg == 0)
		p->size = p->size + write(1, "+", 1);
	if (p->space == 1)
		p->size = p->size + write(1, " ", 1);
	ft_putnbr_fd(i, 1);
	p->size = p->size + ft_size(i, 10);
}

void	ft_print_uhextoa(t_parameters *p, int divider, char *base)
{
	size_t	i;
	char	*dest;
	int		len;

	i = (size_t)va_arg(p->args, unsigned int);
	len = ft_size(i, divider);
	dest = ft_calloc(len + 1, 1);
	if (!dest)
		return ;
	dest[len] = '\0';
	if (p->square == 1 && i != 0 && p->hexcap == 0)
		p->size = p->size + write(1, "0x", 2);
	if (p->square == 1 && i != 0 && p->hexcap == 1)
		p->size = p->size + write(1, "0X", 2);
	p->size = p->size + len;
	while (len--)
	{
		dest[len] = base[i % divider];
		ft_putstr_fd(dest, 1);
		i = i / divider;
	}	
	free(dest);
}

