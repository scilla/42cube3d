/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_dyn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:11:55 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:48:52 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		sprite_collision(t_vector a, t_vector b)
{
	double	dist;

	dist = hypot(a.z - b.z, a.x - b.x);
	if (dist < 25)
		return (1);
	return (0);
}

void	enemy_hit(t_data *d)
{
	t_sprite	**ptr;

	ptr = d->sprites;
	while (*ptr)
	{
		if ((*ptr)->type == 1 && (*ptr)->state == 0)
		{
			if (sprite_collision((*ptr)->pos, d->camera))
			{
				(*ptr)->x_speed *= -1;
				(*ptr)->z_speed *= -1;
				(*ptr)->state = 2;
				(*ptr)->timer = 0;
				d->life -= 1;
			}
		}
		ptr = &(*ptr)->next;
	}
}

void	ammo_pick(t_data *d)
{
	t_sprite	**ptr;
	t_sprite	**con;
	int			i;

	ptr = d->sprites;
	i = 0;
	while (*ptr)
	{
		if ((*ptr)->type == 0)
		{
			if (sprite_collision((*ptr)->pos, d->camera))
			{
				if (d->ammo < 10)
				{
					ptr = delete_sprite(d, i);
					d->ammo++;
					break ;
				}
			}
		}
		i++;
		ptr = &(*ptr)->next;
	}
}

void	hit_enm(t_sprite **con)
{
	(*con)->state = 1;
	(*con)->timer = 0;
	(*con)->x_speed = 0;
	(*con)->z_speed = 0;
}

int		check_coll(t_sprite **ptr, t_sprite **con, int *i, t_data *d)
{
	int			hit;

	hit = 0;
	while (*con)
	{
		if ((*con)->type == 1 &&
		sprite_collision((*ptr)->pos, (*con)->pos))
		{
			ptr = delete_sprite(d, *i);
			hit_enm(con);
			hit = 1;
			(*i)--;
			break ;
		}
		con = &(*con)->next;
	}
	return (hit);
}

void	ammo_hit(t_data *d)
{
	t_sprite	**ptr;
	t_sprite	**con;
	int			i;
	int			hit;

	ptr = d->sprites;
	i = 0;
	while (*ptr)
	{
		hit = 0;
		if ((*ptr)->type == 2)
		{
			con = d->sprites;
			hit = check_coll(ptr, con, &i, d);
		}
		i++;
		if (!hit)
			ptr = &(*ptr)->next;
	}
}
