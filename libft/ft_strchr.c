/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:00:07 by scilla            #+#    #+#             */
/*   Updated: 2021/01/18 17:32:29 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (*(str + i) == (unsigned char)c)
		{
			return ((char*)str + i);
		}
		if (c != 0 && *(str + i) == 0)
		{
			return (0);
		}
		i++;
	}
}
