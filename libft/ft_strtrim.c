/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:46:55 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 15:46:03 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_in_set(char c, const char *set)
{
	while (*(set))
	{
		if (c == *(set))
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*res;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (*(s1 + end))
		end++;
	while (*(s1 + start) && is_in_set(*(s1 + start), set))
		start++;
	while (end > start + 1 && is_in_set(*(s1 + end - 1), set))
		end--;
	if (!(res = malloc(end - start + 1)))
		return (0);
	while (i < end - start)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
