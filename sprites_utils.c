/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:36:53 by scilla            #+#    #+#             */
/*   Updated: 2021/03/28 17:39:16 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		bubble_sprites(t_data *data, int len)
{
	t_vector	cam;
	t_sprite	*spr;
	t_sprite	*tmp;
	t_sprite	**prec;

	cam = data->camera;
	prec = data->sprites;
	spr = *data->sprites;
	while (--len)
	{
		if (hypot(spr->next->pos.z - cam.z, spr->next->pos.x - cam.x) >
		hypot(spr->pos.z - cam.z, spr->pos.x - cam.x))
		{
			tmp = spr->next;
			spr->next = spr->next->next;
			tmp->next = spr;
			*prec = tmp;
			prec = &tmp->next;
		}
		else
		{
			prec = &spr->next;
			spr = spr->next;
		}
	}
}

void		sort_sprites(t_data *data)
{
	int			len;
	int			i;
	t_sprite	*spr;

	len = 0;
	spr = *data->sprites;
	while (spr)
	{
		len++;
		spr = spr->next;
	}
	while (len)
	{
		bubble_sprites(data, len);
		len--;
	}
}

t_sprite	**delete_sprite(t_data *data, int ind)
{
	int			k;
	t_sprite	*spr;
	t_sprite	**prec;

	k = 0;
	prec = data->sprites;
	spr = *data->sprites;
	while (k < ind)
	{
		prec = &spr->next;
		spr = spr->next;
		k++;
	}
	*prec = spr->next;
	free(spr);
	return (prec);
}
