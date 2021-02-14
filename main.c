
#include "main.h"
#include "structs.h"

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_data
{
	t_camera	camera;
	t_xvar		*xvar;
	t_win_list	*win;
	int			height;
	int			width;
}				t_data;

t_data	*init()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->width = 640;
	data->height = 480;
	data->xvar = mlx_init();
	data->win = mlx_new_window(data->xvar, data->width, data->height, "scilla");
	return (data);
}

void	my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel, int x, int y, int color)
{
    char	*dst;

    dst = addr + (y * line_length + x * (bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		main(void)
{
	t_data	*data;
	t_img	*img;
	t_wall	wall = {{0, 0, 0}, 100, 80, 0, 0x00ff0000, 0, 0};
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	(void)wall;
	(void)img;
	data = init();
	img = mlx_new_image(data->xvar, data->width, data->height);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	for (int i = 0; i < 480; i++) {
		my_mlx_pixel_put(addr, line_length, bits_per_pixel, i, i , 0x00ff0000);
	}
	mlx_put_image_to_window(data->xvar, data->win, img, 0, 0);
	mlx_loop(data->xvar);
	return (1);
}
