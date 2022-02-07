/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:44:08 by scilla            #+#    #+#             */
/*   Updated: 2021/03/22 16:16:08 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H
# include "main.h"

void		img_pixel_put(char *addr, t_data *data, t_point p, int col);
int			img_pixel_get(char *addr, t_asset *data, t_point p);
void		add_dist(int *arr, int x, int y, t_world *w);
void		draw_cross(t_data *data, char *addr);
void		draw_circle(t_data *data, char *addr);
t_point		*fill_points(t_point a, t_point b, int rsl);

#endif
