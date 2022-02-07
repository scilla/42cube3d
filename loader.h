#ifndef LOADER_H
# define LOADER_H
# include "main.h"

t_vector	init_camera(t_data *d);
t_asset		load_img(char *path, t_data *data);
t_asset		*load_assets(t_data *data);
t_keys		init_keys();
t_data		*init(char *path);

#endif