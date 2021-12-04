/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:29:21 by scilla            #+#    #+#             */
/*   Updated: 2021/01/21 19:28:02 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned const char		*s;
	unsigned char			stopc;

	stopc = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (n > 0)
	{
		*d = *s;
		if (*d == stopc)
			return (++d);
		d++;
		s++;
		n--;
	}
	return (NULL);
}
