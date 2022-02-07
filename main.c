/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:50:22 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:55:32 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

#ifndef INT32_MAX
# define INT32_MAX 0x7fffffff
#endif

void		new_pkl(t_data *d)
{
	int	x;
	int	z;
	int sbu;
	int	sbo;

	if (d->spawn_time++ % 300)
		return ;
	while (1)
	{
		x = (double)rand() / INT32_MAX * d->world->x_len;
		while (x < d->world->x_len)
		{
			z = (double)rand() / INT32_MAX * d->world->x_len;
			while (z < d->world->z_len)
			{
				sbu = (int)z * d->world->x_len + (int)x;
				sbo = (int)(z * d->world->x_len) / 50 + (int)(x / 50);
				if (d->world->dist[sbu] > 25 && d->map->cells[sbo] == 0)
				{
					spawn_pkl(d, x, z);
					return ;
				}
				z++;
			}
			x++;
		}
	}
}

void		sprite_bounce(t_data *data)
{
	int				coll;
	t_sprite		*spr;

	spr = *data->sprites;
	while (spr && 1)
	{
		spr->pos.x += spr->x_speed;
		spr->pos.z += spr->z_speed;
		coll = wall_collision(data, spr->pos, 20);
		if (coll & 1)
			spr->x_speed *= -1;
		if (coll & 2)
			spr->z_speed *= -1;
		spr = spr->next;
	}
}

int			game_loop(t_data *data)
{
	double			tdif;

	sprite_bounce(data);
	key_move(data);
	//mouse_move(data);
	ammo_hit(data);
	ammo_pick(data);
	enemy_hit(data);
	expire_enm(data);
	expire_pkl(data);
	new_pkl(data);
	data->img = mlx_new_image(data->xvar, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
	&data->line_len, &data->endian);
	render_floor(data);
	render_walls(data);
	render_sprites(data);
	draw_minimap(data);
	draw_hud(data);
	mlx_put_image_to_window(data->xvar, data->win, data->img, 0, 0);
	mlx_destroy_image(data->xvar, data->img);
	return (1);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
	{
		write(1, "Error\nno map path provided\n", 27);
		return (-1);
	}
	data = init(argv[1]);
	mlx_loop_hook(data->xvar, &game_loop, data);
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	//mlx_mouse_hide();
	mlx_loop(data->xvar);
	return (1);
}
