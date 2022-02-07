#ifndef HUD_H
# define HUD_H
# include "main.h"

void	put_cross(t_data *d);
void	draw_asset(t_data *d, t_asset *ass, int dx, int dy);
void	put_hearts(t_data *d);
void	put_ammo(t_data *d);
void	draw_hud(t_data *d);

#endif