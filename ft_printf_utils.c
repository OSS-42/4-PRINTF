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
	char	*s;
	int		j;
	
	i = va_arg(p->args, int);
	if (i < 0)
		p->neg = 1;
	j = 0;
	if (p->plus == 1 && p->neg == 1)
	{	
		s = ft_itoa(i);
		while (s[j])
		{
			p->size = p->size + write(1, &s[j],1);
			j++;
		}
	}
}