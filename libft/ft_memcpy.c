/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:26:00 by scilla            #+#    #+#             */
/*   Updated: 2021/01/21 19:35:10 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	char		*cdst;
	const char	*csrc;

	if (!d && !s && n)
		return (0);
	cdst = d;
	csrc = s;
	while (n > 0)
	{
		*(cdst++) = *(csrc++);
		n--;
	}
	return (d);
}
