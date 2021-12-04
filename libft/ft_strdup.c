/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:37:40 by scilla            #+#    #+#             */
/*   Updated: 2021/01/21 19:36:52 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	n;
	unsigned int	i;
	char			*res;

	i = 0;
	n = 0;
	while (s[n])
	{
		n++;
	}
	n++;
	res = malloc(sizeof(char) * n);
	if (!res)
		return (0);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
