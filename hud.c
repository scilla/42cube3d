/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:33:31 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:33:51 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_asset(t_data *d, t_asset *ass, int dx, int dy)
{
	int		x;
	int		y;
	int		clr;

	x = 0;
	while (x < ass->width)
	{
		y = 0;
		while (y < ass->height)
		{
			clr = img_pixel_get(ass->addr, ass, (t_point){x, y, 0});
			if (!(clr & 0xff000000))
				img_pixel_put(d->addr, d,
				(t_point){dx - ass->width / 2 + x,
				dy - ass->height / 2 + y, 0}, clr);
			y++;
		}
		x++;
	}
}

void	put_cross(t_data *d)
{
	t_asset *ass;

	ass = &d->assets[12];
	draw_asset(d, ass, d->width / 2, d->height / 2);
}

void	put_hearts(t_data *d)
{
	t_asset *ass;
	int		i;

	ass = &d->assets[13];
	i = 0;
	while (i < d->life)
	{
		draw_asset(d, ass, d->width - (50 * (i + 1)), d->height - 50);
		i++;
	}
}

void	put_ammo(t_data *d)
{
	t_asset *ass;
	int		i;

	ass = &d->assets[14];
	i = 0;
	while (i < d->ammo)
	{
		draw_asset(d, ass, d->width - (50 * (i + 1)), d->height - 160);
		i++;
	}
}

void	draw_hud(t_data *d)
{
	put_ammo(d);
	put_hearts(d);
	put_cross(d);
}
