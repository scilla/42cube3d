/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:54:13 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 19:44:38 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t p;

	p = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != 0 && dest_len < size)
		dest_len++;
	while (src[src_len] != 0)
		src_len++;
	if (dest_len >= size)
		return (size + src_len);
	while (src[p] && dest_len + 1 + p < size)
	{
		dest[dest_len + p] = src[p];
		p++;
	}
	dest[dest_len + p] = 0;
	return (src_len + dest_len);
}
