/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:27:26 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 18:10:40 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		magnitude_putnbr(int n)
{
	int	p;

	p = 0;
	if (!n)
		return (1);
	while (n / 10)
	{
		p++;
		n /= 10;
	}
	return (p);
}

int		multiplier(int n)
{
	int	i;

	if (n < 0)
		return (0);
	i = 1;
	while (n > 0)
	{
		i *= 10;
		n--;
	}
	return (i);
}

void	print_uns(unsigned int uns, int fd)
{
	unsigned int	p;
	unsigned int	i;
	int				mult;
	char			c;

	i = 0;
	p = magnitude_putnbr(uns);
	while (i <= p)
	{
		mult = multiplier(p - i);
		c = '0' + (uns / mult);
		write(fd, &c, 1);
		uns -= ((uns / mult) * mult);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	uns;

	if (!n)
	{
		write(fd, "0", 1);
		return ;
	}
	uns = (unsigned int)n;
	if (n < 0)
	{
		uns = (unsigned int)(-1 * n);
		write(fd, "-", 1);
	}
	print_uns(uns, fd);
	return ;
}
