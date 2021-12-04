/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:11:12 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 20:01:21 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		if (!res)
			return (0);
		*res = 0;
		return (res);
	}
	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		*(res + i) = s[start + i];
		i++;
	}
	*(res + i) = 0;
	return (res);
}
