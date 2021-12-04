/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:31:59 by scilla            #+#    #+#             */
/*   Updated: 2021/01/19 14:08:31 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	unsigned int	last;
	int				found;

	found = 0;
	i = 0;
	last = 0;
	while (1)
	{
		if (*(str + i) == (unsigned char)c)
		{
			last = i;
			found = 1;
		}
		if (*(str + i) == 0)
		{
			break ;
		}
		i++;
	}
	if (!found)
		return (0);
	return ((char*)str + last);
}
