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

#include "libftprintf.h"

/*
c = va_arg(args, int)
s = va_arg(args, char *)
d = va_arg(args, int)
i = va_arg(args, int)
u = va_arg(args, unsigned int)
p = va_arg(args, unsigned long)# or #(unsigned long)va_arg(args, void *);
x = va_arg(args, unsigned int)
X = va_arg(args, unsigned int)
*/

static int	ft_size(long nb);

int	ft_size(long nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
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
	p->size = p->size + ft_size(i);
}

void	ft_print_unsigned(t_parameters *p)
{
	unsigned long	i;
	char			*j;
	int				len;

	i = va_arg(p->args, unsigned int);
	len = ft_size(i);
	j = (char *)malloc(sizeof(char) * len + 1);
	if (!j)
		return ;
	j[len] = '\0';
	p->size = p->size + len;
	while (len--)
	{
		j[len] = i % 10 + 48;
		ft_putstr_fd(j, 1);
		i = i / 10;
	}
	free(j);
}

void	ft_print_hexa(t_parameters *p, int divider, char *base)
{
	unsigned long	i;
	char *j;
	int len;
	
	i = va_arg(p->args, unsigned int);
	len = ft_size(i);
	j = (char *)malloc(sizeof(char) * len + 1);
	if (!j)
		return ;
	j[len] = '\0';
	p->size = p->size
}