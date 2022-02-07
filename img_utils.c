/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:43:18 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 15:58:59 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	img_pixel_put(char *addr, t_data *data, t_point p, int col)
{
	char	*dst;

	if (p.x < 0 || p.x >= data->width ||
		p.y < 0 || p.y >= data->height)
		return ;
	dst = addr + ((int)p.y * data->line_len + (int)p.x * (data->bpp / 8));
	*(unsigned int*)dst = col;
}

int		img_pixel_get(char *addr, t_asset *data, t_point p)
{
	int	*dst;

	if (p.x < 0.0|| p.x >= (double)data->width ||
	p.y < 0.0 || p.y >= (double)data->height)
		return (0x00000000);
	dst = (int*)(addr + ((int)p.y * data->line_len + (int)p.x * (data->bpp / 8)));
	return (*dst);
}

void	add_dist(int *arr, int x, int y, t_world *w)
{
	int		i;
	int		m;
	int		xa;
	int		ya;

	m = 0;
	while (m < 100)
	{
		i = 1;
		while (i < 31)
		{
			xa = cos(2.0 * M_PI * m / 100.0) * i + x;
			ya = sin(2.0 * M_PI * m / 100.0) * i + y;
			if (xa >= 0 && ya >= 0 && xa < w->x_len && ya < w->z_len)
			{
				if (w->clms[xa + ya * w->x_len])
					break;
				else if (arr[xa + ya * w->x_len] > i)
					arr[xa + ya * w->x_len] = i;
			}
			else
				break;
			i++;
		}
		m++;
	}
}
