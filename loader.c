/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:06:10 by scilla            #+#    #+#             */
/*   Updated: 2021/03/30 16:44:29 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vector	init_camera(t_data *d)
{
	t_vector	cam;

	cam.x = d->map->cam_x * 50 - 25;
	cam.y = 0;
	cam.z = d->world->z_len - (d->map->cam_y * 50 - 25);
	cam.x_angle = 0;
	cam.y_angle = d->map->cam_rot;
#ifdef __APPLE__
	mlx_mouse_get_pos(d->win, &d->mouse.x, &d->mouse.y);
#endif
#ifdef __linux__
	mlx_mouse_get_pos(d->xvar, d->win, &d->mouse.x, &d->mouse.y);
#endif
	return (cam);
}

t_asset		load_img(char *path, t_data *data)
{
	t_asset	img_data;

	img_data.img = mlx_xpm_file_to_image(data->xvar, path,
	&img_data.width, &img_data.height);
	img_data.addr = mlx_get_data_addr(img_data.img,
	&img_data.bpp, &img_data.line_len, &img_data.endian);
	return (img_data);
}

t_asset		*load_assets(t_data *data)
{
	t_asset	*assets;

	assets = malloc(sizeof(t_asset) * 100);
	assets[0] = load_img(data->map->north_path, data);
	assets[1] = load_img(data->map->east_path, data);
	assets[2] = load_img(data->map->south_path, data);
	assets[3] = load_img(data->map->west_path, data);
	assets[4] = load_img(data->map->sprite_path, data);
	assets[5] = load_img("assets/rat.xpm", data);
	assets[6] = load_img("assets/floor.xpm", data);
	assets[7] = load_img("assets/skyline.xpm", data);
	assets[8] = load_img("assets/pickle3.xpm", data);
	assets[9] = load_img("assets/pickle4.xpm", data);
	assets[10] = load_img("assets/pickle5.xpm", data);
	assets[11] = load_img("assets/rat2.xpm", data);
	assets[12] = load_img("assets/cross.xpm", data);
	assets[13] = load_img("assets/heart.xpm", data);
	assets[14] = load_img("assets/pickleammo.xpm", data);
	return (assets);
}

t_keys		init_keys(void)
{
	t_keys keys;

	keys.a = 0;
	keys.s = 0;
	keys.d = 0;
	keys.w = 0;
	keys.lf = 0;
	keys.rg = 0;
	keys.ctrl = 0;
	keys.spc = 0;
	keys.shft = 0;
	return (keys);
}

void		init_data(t_data *data)
{
	data->width = data->map->x_res;
	data->height = data->map->y_res;
	data->xvar = mlx_init();
	if (!data->xvar) {
		printf("Unable to initialize xvar, exiting...\n");
		exit(1);
	}
	data->assets = load_assets(data);
	data->world = malloc(sizeof(t_world));
	data->world->z_len = data->map->max_z * 50 + 1;
	data->world->x_len = data->map->max_x * 50 + 1;
	data->keys = init_keys();
	data->mv.jmp_t = 0;
	data->mv.crc = 0;
	data->mv.jmp = 0;
	data->ammo = 0;
	data->state = 0;
	data->life = 10;
	data->spawn_time = 0;
	data->world->y_len = 50;
	data->fov = M_PI / 2;
	data->fov = 1;
	data->world->clms = malloc(sizeof(t_clm*) *
	data->world->z_len * data->world->x_len);
	data->world->dist = malloc(sizeof(int) *
	data->world->z_len * data->world->x_len);
	data->world->spawn = malloc(sizeof(char) *
	data->world->z_len * data->world->x_len);
	data->zorder = malloc(sizeof(int) * data->width);
}

t_data		*init(char *path)
{
	t_data		*data;
	int			i;

	(void)path;
	data = malloc(sizeof(t_data));
	parse_input(data, path);
	init_data(data);
	i = 0;
	while (i < data->world->z_len * data->world->x_len)
	{
		data->world->clms[i] = 0;
		data->world->dist[i] = 30;
		i++;
	}
	i = 0;
	while (i < data->width)
		data->zorder[i++] = 9999;
	data->win = mlx_new_window(data->xvar, data->width, data->height, "scilla");
	data->camera = init_camera(data);
	place_walls(data);
	place_sprites(data);
	return (data);
}
