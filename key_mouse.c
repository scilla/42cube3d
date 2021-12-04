#include "main.h"

int		key_press(int keycode, t_data *data)
{
	printf("key prs: %d\n", keycode);
	if (keycode == S || keycode == DW)
		data->keys.s = 1;
	else if (keycode == A)
		data->keys.a = 1;
	else if (keycode == D)
		data->keys.d = 1;
	else if (keycode == W || keycode == UP)
		data->keys.w = 1;
	else if (keycode == LF)
		data->keys.lf = 1;
	else if (keycode == RG)
		data->keys.rg = 1;
	else if (keycode == UP)
		data->keys.w = 1;
	else if (keycode == DW)
		data->keys.s = 1;
	else if (keycode == CTRL)
		data->keys.ctrl = 1;
	else if (keycode == SPC)
		data->keys.spc = 1;
	else if (keycode == SHFT)
		data->keys.shft = 1;
	else if (keycode == ESC)
		exit(1);
	return (1);
}

int		key_release(int keycode, t_data *data)
{
	printf("key rel: %d\n", keycode);
	if (keycode == S || keycode == DW)
		data->keys.s = 0;
	else if (keycode == A)
		data->keys.a = 0;
	else if (keycode == D)
		data->keys.d = 0;
	else if (keycode == W || keycode == UP)
		data->keys.w = 0;
	else if (keycode == LF)
		data->keys.lf = 0;
	else if (keycode == RG)
		data->keys.rg = 0;
	else if (keycode == UP)
		data->keys.w = 0;
	else if (keycode == DW)
		data->keys.s = 0;
	else if (keycode == CTRL)
		data->keys.ctrl = 0;
	else if (keycode == SPC)
		data->keys.spc = 0;
	else if (keycode == SHFT)
		data->keys.shft = 0;
	return (1);
}

void	shoot(t_data *data)
{
	t_sprite	**spr;

	if (data->ammo <= 0)
		return ;
	data->ammo--;
	spr = data->sprites;
	while (*spr)
		spr = &(*spr)->next;
	*spr = malloc(sizeof(t_sprite));
	(*spr)->next = 0;
	(*spr)->asset = malloc(sizeof(t_asset*) * 3);
	(*spr)->asset[0] = &data->assets[8];
	(*spr)->asset[1] = &data->assets[9];
	(*spr)->asset[2] = &data->assets[10];
	(*spr)->pos = data->camera;
	(*spr)->x_speed = 10.0 * sin(data->camera.y_angle);
	(*spr)->z_speed = 10.0 * cos(data->camera.y_angle);
	(*spr)->pos.x += (*spr)->x_speed;
	(*spr)->pos.y += (*spr)->z_speed;
	(*spr)->state = 0;
	(*spr)->type = 2;
	(*spr)->timer = 0;
}

t_vector	add_mov(t_vector dest, int px, int pz, int is_cos)
{
	int			speed;
	double		trig;

	speed = 8;
	if (is_cos & 1)
		trig = cos(dest.y_angle);
	else
		trig = sin(dest.y_angle);
	if (px)
		dest.x = dest.x + speed * trig;
	else
		dest.x = dest.x - speed * trig;
	if (is_cos & 2)
		trig = cos(dest.y_angle);
	else
		trig = sin(dest.y_angle);
	if (pz)
		dest.z = dest.z + speed * trig;
	else
		dest.z = dest.z - speed * trig;
	return (dest);
}

t_vector	asdw(t_data *data)
{
	t_vector	dest;

	dest = data->camera;
	if (data->keys.s)
		dest = add_mov(dest, 0, 0, 2);
	else if (data->keys.a)
		dest = add_mov(dest, 0, 1, 1);
	else if (data->keys.d)
		dest = add_mov(dest, 1, 0, 1);
	else if (data->keys.w)
		dest = add_mov(dest, 1, 1, 2);
	else if (data->keys.lf)
		dest.y_angle -= M_PI / 32;
	else if (data->keys.rg)
		dest.y_angle += M_PI / 32;
	else if (data->keys.ctrl)
		data->mv.crc = 1;
	else if (data->keys.shft)
	{
		data->keys.shft = 0;
		shoot(data);
	}
	return (dest);
}

int		key_move(t_data *data)
{
	t_vector	dest;
	int			coll;

	data->mv.crc = 0;
	if (data->keys.spc)
		data->mv.jmp = 1;
	if (data->mv.jmp)
	{
		if (data->mv.jmp_t++ >= 10)
		{
			data->mv.jmp = 0;
			data->mv.jmp_t = 0;
		}
	}
	dest = asdw(data);
	coll = wall_collision(data, dest, 15);
	if (!(coll & 1))
		data->camera.x = dest.x;
	if (!(coll & 2))
		data->camera.z = dest.z;
	data->camera.y_angle = fix_pi(dest.y_angle);
	return (1);
}

void		mouse_move(t_data *d)
{
	int	x;
	int	y;
	int	dx;

	//mlx_mouse_get_pos(d->xvar, d->win, &x, &y);
	
#ifdef __APPLE__
	mlx_mouse_get_pos(d->win, &x, &y);
	dx = x - d->mouse.x;
	mlx_mouse_move(d->win, d->mouse.x, d->mouse.y);
#endif
#ifdef __linux__
	mlx_mouse_get_pos(d->xvar, d->win, &x, &y);
	dx = x - d->mouse.x;
	mlx_mouse_move(d->xvar, d->win, d->mouse.x, d->mouse.y);
#endif
	d->camera.y_angle = fix_pi(d->camera.y_angle + dx * M_PI / 1000);
	// d->mouse.x = x;
	// d->mouse.y = y;
}
