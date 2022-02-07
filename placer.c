/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:21:16 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 15:51:21 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	spawn_pkl(t_data *data, int x, int z)
{
	t_sprite	*next;
	t_sprite	**spr;

	spr = data->sprites;
	while (*spr)
		spr = &(*spr)->next;
	next = malloc(sizeof(t_sprite));
	*spr = next;
	next->follow = 1;
	next->asset = malloc(sizeof(t_asset*));
	next->asset[0] = &data->assets[4];
	next->pos = (t_vector){x, 0, z, 0, 0, 0};
	next->next = 0;
	next->moving = 0;
	next->type = 0;
	next->x_speed = rand() % 2 + 1;
	next->z_speed = rand() % 2 + 1;
}

void	spawn_enm(t_data *data, int x, int z)
{
	t_sprite	*next;
	t_sprite	**spr;

	spr = data->sprites;
	while (*spr)
		spr = &(*spr)->next;
	next = malloc(sizeof(t_sprite));
	*spr = next;
	next->follow = 1;
	next->asset = malloc(sizeof(t_asset*));
	next->asset[0] = &data->assets[5];
	next->asset[1] = &data->assets[11];
	next->pos = (t_vector){x, 0, z, 0, 0, 0};
	next->next = 0;
	next->moving = 0;
	next->type = 1;
	next->x_speed = rand() % 5 + 1;
	next->z_speed = rand() % 5 + 1;
}

void	place_sprites(t_data *data)
{
	int		i;

	data->sprites = malloc(sizeof(t_sprite*));
	*(data->sprites) = 0;
	i = 0;
	while (i < 5)
	{
		spawn_pkl(data, 300, 300);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		spawn_enm(data, 300, 300);
		i++;
	}
}

void	c_gen_wall(t_data *data, int x, int z, double r)
{
	t_vector	vect;

	vect = (t_vector){x, 0, z, 0, r, 0};
	gen_wall(data->world, vect, 50, &data->assets[0]);
}

void	place_walls(t_data *data)
{
	int			x;
	int			z;
	t_map		*m;

	m = data->map;
	x = 0;
	while (x < m->max_x)
	{
		z = 0;
		while (z < m->max_z)
		{
			if (m->cells[x + z * m->max_x] == 1)
			{
				c_gen_wall(data, x * 50 + 25, (m->max_z - z - 1) * 50, 0);
				c_gen_wall(data, x * 50 + 25,
				(m->max_z - z - 1) * 50 - 50, M_PI);
				c_gen_wall(data, x * 50,
				(m->max_z - z - 1) * 50 - 25, M_PI / 2);
				c_gen_wall(data, x * 50 + 50,
				(m->max_z - z - 1) * 50 - 25, 3 * M_PI / 2);
			}
			z++;
		}
		x++;
	}
}
