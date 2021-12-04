#ifndef SPRITE_DYN_H
# define SPRITE_DYN_H
# include "main.h"

int		sprite_collision(t_vector a, t_vector b);
void	ammo_hit(t_data *d);
void	ammo_pick(t_data *d);
void	enemy_hit(t_data *d);

#endif