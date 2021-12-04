#include "main.h"

void	draw_dot(t_data *d, t_point p, int size, int clr)
{
	int		i;
	int		n;
	t_point	q;

	i = 0;
	q = p;
	while (i < size)
	{
		n = 0;
		q.x = p.x + i;
		while (n < size)
		{
			q.y = p.y + n;
			img_pixel_put(d->addr, d, q, clr);
			n++;
		}
		i++;
	}
}