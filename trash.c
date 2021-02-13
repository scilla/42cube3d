
void get_pixel_color (Display *d, int x, int y, XColor *color)
{
  XImage *image;
  image = XGetImage (d, RootWindow (d, DefaultScreen (d)), x, y, 1, 1, AllPlanes, XYPixmap);
  color->pixel = XGetPixel (image, 0, 0);
  XFree (image);
  XQueryColor (d, DefaultColormap(d, DefaultScreen (d)), color);
}


void	apply_to_win(t_xvar *mlx_ptr, t_win_list *win_ptr, int height, int width, int (*f)(int))
{
	int 	x;
	int		y;
	int		clr;
	XColor	xclr;

	x = 0;
	(void)f;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			//printf("x%d, y%d\n", x, y);
			get_pixel_color(mlx_ptr->display, x, y, &xclr);
			clr = xclr.red * 0x00010000 + xclr.green * 0x00000100 + xclr.blue * 0x00000001;
			//clr = f(clr);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, clr);
			y++;
		}
		x++;
	}
	
}

int		point_one_less(int n)
{
	return ((n * 10) / 9);
}