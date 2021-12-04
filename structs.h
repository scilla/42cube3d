/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:25:45 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:25:45 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_trn
{
	t_point	a;
	t_point	b;
	t_point	c;
}				t_trn;

typedef	struct	s_vector
{
	double	x;
	double	y;
	double	z;
	double	x_angle;
	double	y_angle;
	double	z_angle;
}				t_vector;

typedef struct	s_wall2
{
	t_vector	normal;
	int		height;
	int		width;
	int		color;
	int		has_texture;
	void	*texture;
}				t_wall2;

typedef struct	s_wall
{
	t_vector	normal;
	t_trn	*trn;
	int		len_trn;
	int		height;
	int		width;
	int		color;
	int		has_texture;
	void	*texture;
}				t_wall;

typedef	struct	s_asset
{
	void		*img;
	void		*addr;
	int			height;
	int			width;
	int			bpp;
	int			line_len;
	int			endian;
}				t_asset;

typedef struct	s_clm
{
	int		*arr;
	int		len;
	//t_clm	*next;
}				t_clm;

typedef struct	s_sprite
{
	t_asset				**asset;
	t_vector			pos;
	t_bool				follow;
	struct	s_sprite	*next;
	t_bool				moving;
	int					x_speed;
	int					z_speed;
	char				state;
	char				type;
	int					timer;

}				t_sprite;

typedef struct	s_rend
{
	int			ss;
	int			tt;
	int			ll;
	int			x;
	int			y;
	int			z;
	int			n;
	int			i;
	int			sbu;
	double		rot;
	double		dist;
	double		dx;
	double		dy;
	double		dz;
	t_asset		*ass;
	t_sprite	*spr;
	t_point		p;
}				t_rend;

typedef struct	s_world
{
	int		z_len;
	int		x_len;
	int		y_len;
	t_clm	**clms;
	int		*dist;
	char	*spawn;
}				t_world;

typedef struct	s_map
{
	int		x_res;
	int		y_res;
	int		max_x;
	int		max_z;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*sprite_path;
	int		floor;
	int		ceil;
	int		*cells;
	int		cam_x;
	int		cam_y;
	double	cam_rot;
}				t_map;

typedef struct	s_keys
{
	char	a;
	char	s;
	char	d;
	char	w;
	char	lf;
	char	rg;
	char	ctrl;
	char	spc;
	char	shft;
}				t_keys;

typedef struct timespec t_timespec;

typedef struct s_data	t_data;

typedef struct	s_mouse
{
	int		x;
	int		y;
}				t_mouse;

typedef struct	s_move
{
	int			crc;
	int			jmp;
	int			jmp_t;
}				t_move;

typedef struct s_data
{
	t_vector	camera;
	void		*img;
	void		*addr;
	void		*xvar;
	void		*win;
	int			height;
	int			width;
	int			bpp;
	int			line_len;
	int			endian;
	int			state;
	int			screenx;
	int			screeny;
	t_sprite	**sprites;
	t_wall		*walls;
	int			walls_len;
	int			*zorder;
	t_asset		*assets;
	t_timespec	last;
	t_world		*world;
	double		fov;
	t_map		*map;
	t_keys		keys;
	t_mouse		mouse;
	t_move		mv;
	int			ammo;
	int			life;
	int			spawn_time;
}				t_data;

#endif
