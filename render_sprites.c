/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:23:32 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:22:47 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			check_bounds(t_data *data, t_rend *vars, int i)
{
	vars->p = (t_point){data->width / 2 - (data->width / 2) * (vars->rot /
	(cos(vars->rot) * sqrtf(cos(vars->rot)) * M_PI / 4)) +
	i - vars->ll / 2, vars->ss - vars->n, 0};
	if (vars->p.y < 0 || vars->p.x < 0 || vars->p.y >= data->height ||
	vars->p.x >= data->width || data->zorder[(int)vars->p.x] <= (int)vars->dist)
		return (0);
	return (1);
}

void		print_spr(t_rend *vars, t_data *data)
{
	int		i;

	i = 0;
	while (i < vars->ll)
	{
		vars->x = ((double)vars->ass->width / vars->ll) * i;
		vars->n = -2;
		while (vars->n < vars->ss - vars->tt - 2)
		{
			vars->n += 2;
			if (!check_bounds(data, vars, i))
				continue ;
			vars->y = ((double)vars->ass->height /
			(vars->ss - vars->tt)) * vars->n;
			vars->sbu = img_pixel_get(vars->ass->addr, vars->ass,
			(t_point){vars->x, vars->ass->height - vars->y - 1, 0});
			vars->sbu = div_color(vars->sbu, 150.0 / vars->dist);
			if (vars->spr->state == 2)
				vars->sbu += 0x00550000;
			if ((vars->sbu & 0xff000000) != 0xff000000)
				draw_dot(data, vars->p, 2, vars->sbu);
		}
		i += 2;
	}
}

void		calc_limits_spr(t_rend *vars, t_data *data)
{
	int		shift;

	vars->ll = 50 * data->height / vars->dist;
	vars->tt = -vars->ll / 2 + data->height / 2;
	vars->ss = vars->ll / 2 + data->height / 2;
	if (data->mv.crc)
	{
		shift = (data->height / 2 - vars->ss) / 2;
		vars->ss += shift;
		vars->tt += shift;
	}
	else if (data->mv.jmp)
	{
		if (data->mv.jmp_t < 5)
			shift = (data->mv.jmp_t / 5.0) *
			(data->height / 2 - vars->ss) / 2.0;
		else
			shift = ((10 - data->mv.jmp_t) / 5.0) *
			(data->height / 2 - vars->ss) / 2.0;
		vars->ss -= shift;
		vars->tt -= shift;
	}
}

void		sel_asset(t_data *data, t_rend *vars)
{
	t_asset		*ass;

	if (vars->spr->type == 2)
		vars->ass = vars->spr->asset[(vars->spr->timer / 3) % 3];
	else if (vars->spr->type == 1)
	{
		if (vars->spr->state == 1)
			vars->ass = vars->spr->asset[1];
		else
			vars->ass = vars->spr->asset[0];
	}
	else
		vars->ass = vars->spr->asset[0];
}

void		render_sprites(t_data *data)
{
	int			k;
	double		dist;
	t_asset		*ass;
	t_rend		vars;

	sort_sprites(data);
	k = 0;
	vars.spr = *data->sprites;
	while (vars.spr)
	{
		k++;
		vars.rot = (atan2(vars.spr->pos.z - data->camera.z,
		vars.spr->pos.x - data->camera.x)) + data->camera.y_angle - M_PI / 2;
		vars.rot = fix_pi(vars.rot);
		vars.dist = hypot(vars.spr->pos.x - (int)data->camera.x,
		vars.spr->pos.z - (int)data->camera.z);
		if (cos(vars.rot) > 0 && vars.dist > 20 &&
		vars.rot > -data->fov * 1.1 && vars.rot < data->fov * 1.1)
		{
			sel_asset(data, &vars);
			calc_limits_spr(&vars, data);
			print_spr(&vars, data);
		}
		vars.spr = vars.spr->next;
	}
}
