/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:56:07 by scilla            #+#    #+#             */
/*   Updated: 2021/03/29 18:58:14 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	expire_enm(t_data *d)
{
	t_sprite	**ptr;
	int			i;

	ptr = d->sprites;
	i = 0;
	while (*ptr)
	{
		if ((*ptr)->type == 1)
		{
			if ((*ptr)->state == 1 &&
			(*ptr)->timer++ > 50)
			{
				ptr = delete_sprite(d, i--);
				return ;
			}
			if ((*ptr)->state == 2 &&
			(*ptr)->timer++ > 50)
				(*ptr)->state = 0;
		}
		i++;
		ptr = &(*ptr)->next;
	}
}

void	expire_pkl(t_data *d)
{
	t_sprite	**ptr;
	int			i;
	int			hit;

	ptr = d->sprites;
	i = 0;
	while (*ptr)
	{
		hit = 0;
		if ((*ptr)->type == 2)
		{
			if ((*ptr)->timer++ > 150)
			{
				ptr = delete_sprite(d, i--);
				hit = 1;
				break ;
			}
		}
		i++;
		if (!hit)
			ptr = &(*ptr)->next;
	}
}
