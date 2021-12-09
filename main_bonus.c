/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:50:22 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:06:54 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "main.h"
#include "structs.h"
#include "key_mouse.h"

#ifndef INT32_MAX
# define INT32_MAX 0x7fffffff
#endif

void		new_pkl(t_data *d)
{
	int	x;
	int	z;
	int sbu;
	int	done;
	int	sbo;

	done = 0;
	x = (double)rand() / INT32_MAX * d->world->x_len;
	while (x < d->world->x_len)
	{
		z = (double)rand() / INT32_MAX  * d->world->x_len;
		while (z < d->world->z_len)
		{
			sbu = (int)z * d->world->x_len + (int)x;
			sbo = (int)(z * d->world->x_len) / 50 + (int)(x / 50);
			if (d->world->dist[sbu] > 25 && d->map->cells[sbo] == 0)
			{
				printf("spawn %d %d\n", x, z);
				spawn_pkl(d, x, z);
				done = 1;
				return ;
			}
			z++;
		}
		x++;
	}
}

int			game_loop(t_data* data)
{
	double			tdif;
	struct timespec end;
	t_sprite		*spr;
	int				coll;

	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	tdif = (end.tv_sec - data->last.tv_sec) * 1000000 +
	(end.tv_nsec - data->last.tv_nsec) / 1000;
	// if (1.0 / (tdif / 1000000.0) > 30)
	// 	return (1);
	expire_enm(data);
	expire_pkl(data);
	if (data->spawn_time++ > 100)
	{
		data->spawn_time = 0;
		new_pkl(data);
	}
	key_move(data);
	mouse_move(data);
	ammo_hit(data);
	enemy_hit(data);
	data->last = end;
	data->img = mlx_new_image(data->xvar, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
	&data->line_len, &data->endian);
	render_floor(data);
	render_skybox(data);
	render_walls(data);
	render_sprites(data);
	draw_minimap(data);
	draw_hud(data);
	// print_debug(data, tdif);
	mlx_put_image_to_window(data->xvar, data->win, data->img, 0, 0);
	mlx_destroy_image(data->xvar, data->img);
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
	return (1);
}

int		enter_win(t_data *data)
{
	printf("enter_win\n");
	return (1);
}

int		exit_win(t_data *data)
{
	printf("enter_win\n");
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

	for (int i = 0; i < data->world->x_len; i++)
	{
		break;
		for (int n = 0; n < data->world->z_len; n++)
		{
			//int dd = data->world->dist[n * data->world->x_len + i];
			//dd = dd > 9 ? 9 : dd;
			//printf("%d", dd);
			int dd = (long long int)data->world->clms[n * data->world->x_len + i];
			dd = dd > 0 ? 1 : 0;
			printf("%d", dd);
		}
		printf("\n");
	}
	clock_gettime(CLOCK_MONOTONIC_RAW, &data->last);
	mlx_loop_hook(data->xvar, &game_loop, data);
	//game_loop(data);
	mlx_hook(data->win, 2, 1L<<0, &key_press, data);
	mlx_hook(data->win, 3, 1L<<1, &key_release, data);
	// mlx_hook(data->win, 9, 0L, &enter_win, data);
	// mlx_hook(data->win, 10, 0L, &exit_win, data);
	mlx_mouse_hook(data->win, &mouse_key, data);
	mlx_mouse_hide(data->xvar, data->win);
	//start_music();
	mlx_loop(data->xvar);
	return (1);
}
