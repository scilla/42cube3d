
#include "main.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int		_main(void)
{
	t_xvar	*mlx_ptr;
	t_win_list	*win_ptr;
/*
	int		ixar[] = {0, -1, 1};
	int		iyar[] = {0, -1, 1};
*/
	//srand(time(NULL) * 0);
	srand(20);
	int r;
	//float rf;

	int		H = 720, W = 1024;

	int		x = 0;
	int		y = 0;
	/*
	int		ix = 1, iy = 1, nx = 1, ny = 1;
*/

	//unsigned int clr = 0xff0088aa;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, W, H, "scilla");
	while (1) {
		//printf("%2d,%2d\n", x, y);
		x++;
		if (x == W)
		{
			x = 0;
			y++;
			if (y == H)
			{
				break;
			}
		}
		r = rand();
		//rf = ((float)r / RAND_MAX ) * 0xFF;
		//clr = rf * 21;
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, r);
		usleep(200);
		
	}
	mlx_loop(mlx_ptr);
	(void)win_ptr;
	return (1);
}
