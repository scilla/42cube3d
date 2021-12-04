/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:24:50 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 19:44:38 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = s1;
	c2 = s2;
	while (i < n)
	{
		if (*(c1 + i) != *(c2 + i))
		{
			return (*(c1 + i) - *(c2 + i));
		}
		i++;
	}
	return (0);
}
