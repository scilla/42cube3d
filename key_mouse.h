#ifndef KEY_MOUSE_H
# define KEY_MOUSE_H
# include "main.h"

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		mouse_key(int button, int x, int y, t_data *data);
int		key_move(t_data *data);
void	mouse_move(t_data *d);

#endif