#include "main.h"

t_point rotate_point(double angle, t_point p)
{
	double	s;
	double	c;
	double	xnew;
	double	ynew;

	s = sin(angle);
	c = cos(angle);
	xnew = p.x * c - p.y * s;
	ynew = p.x * s + p.y * c;
	p.x = xnew;
	p.y = ynew;
	return p;
}

double		fix_pi(double rot)
{
	if (rot < -M_PI)
		rot += 2 * M_PI;
	if (rot > M_PI)
		rot -= 2 * M_PI;
	return (rot);
}

char *ftoa(float f)
{
	static char		buf[17];
	char			*cp = buf;
	unsigned long	l, rem;
	// NOOOO
    if (f < 0)
	{
		*cp++ = '-';
		f = -f;
	}
	l = (unsigned long)f;
	f -= (float)l;
	rem = (unsigned long)(f * 1e6);
	sprintf(cp, "%lu.%6.6lu", l, rem);
	return buf;
}

int			div_color(int cl, double mlt)
{
	int	x;
	int	r;
	int	g;
	int	b;
	int	res;

	if (mlt >= 1.0)
		return (cl);
	mlt -= 0.05;
	if (mlt <= 0)
		return (0);
	x = cl & 0xff000000;
	r = (double)((cl >> 16) & 0xff) * mlt;
	if (r > 255)
		r = 255;
	g = (double)((cl & 0xff00) >> 8) * mlt;
	if (g > 255)
		g = 255;
	b = (double)((cl & 0xff)) * mlt;
	if (b > 255)
		b = 255;
	res = x + (r << 16) + (g << 8) + b;
	return (res);
}