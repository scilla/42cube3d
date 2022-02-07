#ifndef PLACER_H
# define PLACER_H
# include "main.h"

void		place_sprites(t_data *data);
void		place_walls(t_data *data);
void		spawn_pkl(t_data *data, int x, int z);
void		spawn_enm(t_data *data, int x, int z);

#endif