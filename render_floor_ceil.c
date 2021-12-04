/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:41:09 by scilla            #+#    #+#             */
/*   Updated: 2021/03/28 18:43:24 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		floor_mvmtn(t_data *data, t_rend *vars, int b)
{
	if (data->mv.crc)
	{
		vars->dy = b * (data->world->y_len * 4.0) / data->height;
	}
	else if (data->mv.jmp)
	{
		if (data->mv.jmp_t < 5)
			vars->dy = b * (2.0 * data->world->y_len *
			((10.0 - data->mv.jmp_t) / 10.0)) / data->height;
		else
			vars->dy = b * (2.0 * data->world->y_len *
			((data->mv.jmp_t + 0.0) / 10.0)) / data->height;
	}
	else
		vars->dy = b * (2.0 * data->world->y_len) / data->height;
}

void		pos_and_clr(t_data *data, t_rend *vars, t_vector cam)
{
	vars->z = cam.z - vars->dz * 50.0 / vars->dy;
	vars->x = cam.x + vars->dx * 50.0 / vars->dy;
	vars->z = vars->z < 0 ? data->assets[6].height + vars->z : vars->z;
	vars->x = vars->x < 0 ? data->assets[6].width + vars->x : vars->x;
	vars->p = (t_point){-vars->i + data->width / 2,
	data->height / 2 + vars->n, 0};
	vars->sbu = img_pixel_get(data->assets[6].addr, &data->assets[6],
	(t_point){vars->z % data->assets[6].height,
	vars->x % data->assets[6].width, 0});
	vars->sbu = div_color(vars->sbu, 50.0 / hypot(vars->dz * 50.0 /
	vars->dy, vars->dx * 50.0 / vars->dy));
}

void		render_floor(t_data *data)
{
	t_vector	cam;
	t_rend		vars;

	vars.i = -data->width / 2;
	cam = data->camera;
	cam.y_angle -= M_PI / 2;
	cam.y_angle = fix_pi(cam.y_angle);
	while (vars.i < data->width / 2)
	{
		vars.dx = (50.0 * cos(cam.y_angle)) +
		((sin(cam.y_angle) * 50.0 * vars.i / (double)data->width));
		vars.dz = (50.0 * sin(cam.y_angle)) -
		((cos(cam.y_angle) * 50.0 * vars.i / (double)data->width));
		vars.n = 0;
		while (vars.n < data->height / 2)
		{
			floor_mvmtn(data, &vars, vars.n);
			pos_and_clr(data, &vars, cam);
			draw_dot(data, vars.p, 2, vars.sbu);
			vars.n += 2;
		}
		vars.i += 2;
	}
	cam.y_angle += M_PI / 2;
}
