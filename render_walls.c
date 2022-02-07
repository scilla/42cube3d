/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:46:10 by scilla            #+#    #+#             */
/*   Updated: 2021/03/28 16:46:30 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		calc_limits(t_rend *vars, t_data *data)
{
	int	shift;
	int ll;

	ll = (int)(data->world->y_len * data->height / vars->dist);
	vars->tt = -ll / 2 + data->height / 2;
	vars->ss = ll / 2 + data->height / 2;
	if (data->mv.crc)
	{
		shift = (data->height / 2 - vars->ss) / 2;
		vars->ss += shift;
		vars->tt += shift;
	}
	else if (data->mv.jmp)
	{
		if (data->mv.jmp_t < 5)
			shift = (data->mv.jmp_t / 2.5) *
			(data->height / 2 - vars->ss) / 2.0;
		else
			shift = ((10 - data->mv.jmp_t) / 2.5) *
			(data->height / 2 - vars->ss) / 2.0;
		vars->ss -= shift;
		vars->tt -= shift;
	}
}

void		calc_x_z(t_rend *vars, t_data *d)
{
	double	rot;

	rot = d->camera.y_angle + ((double)vars->i * d->fov /
	(double)d->width) * sqrt(cos((double)vars->i * d->fov /
	(double)d->width));
	vars->rot = fix_pi(rot);
	vars->x = ((double)d->camera.x + sin(vars->rot) * (double)vars->n);
	vars->z = (double)d->camera.z + cos(vars->rot) * (double)vars->n;
}

void		print_clm(t_data *data, t_rend *vars, t_clm *clm, int m)
{
	int		clr;
	t_point	p;

	clr = clm->arr[(int)(m * (clm->len / (double)(vars->ss - vars->tt)))];
	p = (t_point){vars->i + data->width / 2,
		vars->ss - m,
		0};
	if (p.y < 0 || p.y >= data->height)
		return ;
	clr = div_color(clr, 150.0 / vars->dist);
	img_pixel_put(data->addr, data, p, clr);
	p.y--;
	img_pixel_put(data->addr, data, p, clr);
}

int			calc_clm(t_data *data, t_rend *vars)
{
	t_clm	*clm;
	int		m;

	vars->sbu = vars->z * data->world->x_len + vars->x;
	clm = data->world->clms[vars->sbu];
	if (clm)
	{
		data->zorder[vars->i + data->width / 2] = vars->n;
		m = -2;
		vars->dist = hypot(-vars->x + (int)data->camera.x, -vars->z +
		(int)data->camera.z) * cos(data->camera.y_angle - vars->rot);
		calc_limits(vars, data);
		while (m < vars->ss - vars->tt - 2)
		{
			m += 2;
			print_clm(data, vars, clm, m);
		}
		return (1);
	}
	return (0);
}

void		render_walls(t_data *data)
{
	int		dd;
	t_rend	vars;

	vars.i = -data->width / 2;
	while (vars.i < data->width / 2)
	{
		vars.n = 1;
		while (vars.n < 6000)
		{
			calc_x_z(&vars, data);
			if (vars.x > data->world->x_len || vars.x < 0 ||
			vars.z > data->world->z_len || vars.z < 0)
				break ;
			if (calc_clm(data, &vars))
				break ;
			dd = data->world->dist[vars.sbu] / 2;
			dd = dd == 0 ? 1 : dd;
			vars.n += dd;
		}
		vars.i++;
	}
}
