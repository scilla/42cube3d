/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:31:58 by scilla            #+#    #+#             */
/*   Updated: 2021/01/21 19:36:22 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		*(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
