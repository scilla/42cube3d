/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:11:38 by scilla            #+#    #+#             */
/*   Updated: 2021/01/31 16:55:34 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strappend(char **s1, char *s2)
{
	unsigned int	i;
	unsigned int	n;
	char			*res;

	i = 0;
	while (*(*s1 + i))
		i++;
	n = i;
	while (*(s2 + i - n))
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	n = 0;
	i = 0;
	while (*(*s1 + i))
	{
		res[i] = *(*s1 + i);
		i++;
	}
	while (*(s2 + n))
		res[i++] = *(s2 + n++);
	res[i] = 0;
	free(*s1);
	*s1 = res;
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *scp;

	scp = b;
	while (len--)
		*scp++ = c;
	return (b);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	unsigned int	i;
	int				ind;

	i = 0;
	if (!dst && !src && n)
		return (0);
	d = dst;
	s = src;
	while (i < n)
	{
		if (d <= s)
			ind = i;
		else
			ind = n - i - 1;
		*(d + ind) = *(s + ind);
		i++;
	}
	return (dst);
}
