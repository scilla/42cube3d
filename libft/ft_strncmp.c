/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:01:17 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 19:44:38 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] == s2[i] && s1[i] != 0)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
