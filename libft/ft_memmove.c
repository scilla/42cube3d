/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:15 by scilla            #+#    #+#             */
/*   Updated: 2021/01/22 18:07:11 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	backward(char *d, const char *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(d + n - i - 1) = *(s + n - i - 1);
		i++;
	}
	return ;
}

void	forward(char *d, const char *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return ;
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	if (!dst && !src && n)
		return (0);
	d = dst;
	s = src;
	if (d <= s)
	{
		forward(d, s, n);
	}
	else
	{
		backward(d, s, n);
	}
	return (dst);
}
