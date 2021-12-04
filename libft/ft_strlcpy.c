/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:45 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 16:27:59 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		n;
	char		*d;
	const char	*s;

	if (!dst || !src)
		return (0);
	n = 0;
	d = dst;
	s = src;
	while (*(s + n))
	{
		n++;
	}
	i = 0;
	while (i + 1 < size && *(s + i))
	{
		*(d + i) = *(s + i);
		i++;
	}
	if (size)
		*(d + i) = 0;
	return (n);
}
