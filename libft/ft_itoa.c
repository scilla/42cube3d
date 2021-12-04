/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:51:38 by scilla            #+#    #+#             */
/*   Updated: 2021/01/21 19:45:21 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		magnitude(int n)
{
	unsigned int	p;

	p = 0;
	if (!n)
		return (1);
	if (n < 0)
		p++;
	while (n)
	{
		p++;
		n /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	unsigned int	p;
	unsigned int	i;
	int				sign;
	char			*res;

	i = 0;
	p = magnitude(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	res = malloc(sizeof(char) * (p + 1));
	if (!res)
		return (0);
	if (sign < 0)
		res[0] = '-';
	res[p] = 0;
	if (!n)
		res[0] = '0';
	while (n)
	{
		res[p - i - 1] = '0' + (n % 10) * sign;
		n /= 10;
		i++;
	}
	return (res);
}
