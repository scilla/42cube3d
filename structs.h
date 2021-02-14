/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:25:45 by scilla            #+#    #+#             */
/*   Updated: 2021/02/14 23:23:53 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct s_triangle
{
	t_point	a;
	t_point	b;
	t_point	c;
}				t_triangle;

typedef struct	s_wall
{
	t_point	pos;
	int		height;
	int		width;
	int		y_angle;
	int		color;
	int		has_texture;
	t_img	*texture;
}				t_wall;

typedef	struct	s_camera
{
	t_point	pos;
	int		x_angle;
	int		y_angle;
}				t_camera;


#endif
