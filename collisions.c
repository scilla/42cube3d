/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:12:10 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:19:00 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_h(t_world *w, t_vector p, int i, int n)
{
	if (p.x - i < 0 || p.x + i >= w->x_len ||
		w->clms[(int)(p.z + n) * w->x_len + (int)p.x - i] ||
		w->clms[(int)(p.z + n) * w->x_len + (int)p.x + i] ||
		w->clms[(int)(p.z - n) * w->x_len + (int)p.x - i] ||
		w->clms[(int)(p.z - n) * w->x_len + (int)p.x + i])
		return (1);
	return (0);
}

int		check_v(t_world *w, t_vector p, int i, int n)
{
	if (p.z - i < 0 || p.z + i >= w->z_len ||
		w->clms[(int)(p.z + i) * w->x_len + (int)p.x - n] ||
		w->clms[(int)(p.z + i) * w->x_len + (int)p.x + n] ||
		w->clms[(int)(p.z - i) * w->x_len + (int)p.x - n] ||
		w->clms[(int)(p.z - i) * w->x_len + (int)p.x + n])
		return (1);
	return (0);
}

int		wall_collision(t_data *data, t_vector p, int dist)
{
	int		res;
	int		i;
	int		n;

	res = 0;
	i = 0;
	while (++i < dist)
	{
		n = 1;
		while (n <= i / 2 + 1)
		{
			if (!(res & 1))
			{
				if (check_h(data->world, p, i, n))
					res = res | 1;
			}
			if (!(res & 2))
			{
				if (check_v(data->world, p, i, n))
					res = res | 2;
			}
			n++;
		}
	}
	return (res);
}
