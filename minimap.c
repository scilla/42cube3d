/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:27:39 by scilla            #+#    #+#             */
/*   Updated: 2021/03/29 18:29:39 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_enemies(t_data *d)
{
	t_sprite	**spr;
	t_point		p;
	int			clr;

	spr = d->sprites;
	while (*spr)
	{
		p = (t_point){(*spr)->pos.x - d->camera.x,
		(*spr)->pos.z - d->camera.z, 0};
		p = rotate_point(d->camera.y_angle + M_PI, p);
		p = (t_point){300 - p.x, d->height + p.y - 200, 0};
		clr = 0x00ff0000;
		if ((*spr)->type == 0 || (*spr)->type == 2)
			clr = 0x0000ff00;
		if (p.x >= 0 && p.x < 600 && p.y >= d->height - 400 && p.y < d->height)
			draw_dot(d, p, 4, clr);
		spr = &(*spr)->next;
	}
}

int		map_clr(t_point p, t_data *d)
{
	int	clr;

	clr = 0;
	if (d->camera.z + p.y < 0 || d->camera.z + p.y >= d->world->z_len ||
	d->camera.x + p.x < 0 || d->camera.x + p.x >= d->world->x_len)
		clr = 0;
	else if (d->world->clms[(int)(d->camera.z + p.y) *
	d->world->x_len + (int)(d->camera.x + p.x)])
		clr = 0x00ffff00;
	return (clr);
}

void	draw_minimap(t_data *d)
{
	int		x;
	int		z;
	t_point	p;
	int		clr;

	x = -300;
	while (x < 300)
	{
		z = -200;
		while (z < 200)
		{
			p = (t_point){x, z, 0};
			p = rotate_point(-d->camera.y_angle + M_PI, p);
			clr = map_clr(p, d);
			p = (t_point){300 - x, d->height + z - 200, 0};
			if (clr)
				img_pixel_put(d->addr, d, p, clr);
			z++;
		}
		x++;
	}
	p = (t_point){300, d->height - 200, 0};
	draw_dot(d, p, 4, 0x00ffffff);
	add_enemies(d);
}
