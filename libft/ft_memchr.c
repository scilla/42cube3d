/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:22:35 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 19:44:38 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*p;

	i = 0;
	p = s;
	while (i < n)
	{
		if (*(p + i) == (unsigned char)c)
		{
			return (void*)(p + i);
		}
		i++;
	}
	return (NULL);
}
