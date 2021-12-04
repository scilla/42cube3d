/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:05:13 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 15:48:49 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	p;
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (0);
	p = ft_strlen(s);
	res = malloc(sizeof(char) * (p + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < p)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
