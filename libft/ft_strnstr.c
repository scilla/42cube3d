/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:48:14 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 19:44:38 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (!little[0])
		return (char*)(big);
	while (big[i] && i < len)
	{
		n = 0;
		while (big[i + n] == little[n] && i + n < len)
		{
			if (!little[n + 1])
			{
				return (char*)(big + i);
			}
			n++;
		}
		i++;
	}
	return (0);
}
