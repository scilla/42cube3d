/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:19:41 by scilla            #+#    #+#             */
/*   Updated: 2021/03/28 17:19:49 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_skybox(t_data *d)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		clr;

	y = 0;
	while (y < d->height / 2)
	{
		x = 0;
		while (x < d->width)
		{
			dx = (d->assets[7].width) *
			(d->camera.y_angle + M_PI) / (M_PI * 2) + x;
			dx = dx < 0 ? dx + d->assets[7].width : dx;
			dx = dx >= d->assets[7].width ? dx - d->assets[7].width : dx;
			dy = d->assets[7].height * (y / (d->height / 2.0));
			clr = img_pixel_get(d->assets[7].addr,
			&d->assets[7], (t_point){dx, dy, 0});
			draw_dot(d, (t_point){x, y, 0}, 2, clr);
			x += 2;
		}
		y += 2;
	}
}
