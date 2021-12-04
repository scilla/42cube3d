/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_wall->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:43:19 by scilla            #+#    #+#             */
/*   Updated: 2021/02/19 17:08:18 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "structs.h"
#include "img_utils.h"

t_clm	*gen_clm(t_asset *ass, int i, int width)
{
	t_clm	*clm;
	int		n;

	clm = malloc(sizeof(t_clm));
	clm->len = ass->height;
	clm->arr = malloc(sizeof(int) * ass->height);
	n = 0;
	while (n < ass->height)
	{
		clm->arr[ass->height - n - 1] = img_pixel_get(ass->addr,
		ass, (t_point){((double)ass->width/width) * i, n, 0});
		n++;
	}
	return (clm);
}

void	gen_wall(t_world *world, t_vector vect, int width, t_asset *ass)
{
	t_point	start;
	t_point	end;
	int		i;
	int		x;
	int		y;

	start = (t_point){(-width / 2.0) * cos(vect.y_angle) + vect.x, 0,
	(-width / 2.0) * sin(vect.y_angle) + vect.z};
	end = (t_point){(width / 2.0) * cos(vect.y_angle) + vect.x, 0,
	(width / 2.0) * sin(vect.y_angle) + vect.z};
	i = -1;
	while (i < width - 1)
	{
		i++;
		x = (int)(start.x + ((end.x - start.x) / width) * i);
		y = (int)(start.z + ((end.z - start.z) / width) * i);
		if (x < 0 || x >= world->x_len || y < 0 || y >= world->z_len)
			continue;
		add_dist(world->dist, x, y, world);
		world->clms[y * world->x_len + x] = gen_clm(ass, i, width);
	}
}
