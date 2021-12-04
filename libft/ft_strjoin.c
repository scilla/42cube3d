/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:35:58 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 16:19:19 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	n;
	char			*res;

	if (!s1 || !s2)
		return (0);
	i = 0;
	n = 0;
	while (*(s1 + i))
		i++;
	while (*(s2 + n++))
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	n = 0;
	i = 0;
	while (*(s1 + i))
	{
		res[i] = *(s1 + i);
		i++;
	}
	while (*(s2 + n))
		res[i++] = *(s2 + n++);
	res[i] = 0;
	return (res);
}
