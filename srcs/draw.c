#include "fractol.h"

uint32_t
	get_color(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	color;

	color = r;
	color <<= 8;
	color |= g;
	color <<= 8;
	color |= b;
	return (color);
}

void
	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_bool
	include_mandelbrot_set(t_complex c)
{
	int			i;
	t_complex	z;
	t_complex	p;
	t_complex	tmp;

	z[R] = 0.0;
	z[I] = 0.0;
	i = -1;
	while (++i < LOOP)
	{
		p[R] = z[R] * z[R];
		p[I] = z[I] * z[I];
		if (4.0 < p[R] + p[I])
			return (i);
		tmp[R] = p[R] - p[I];
		tmp[I] = z[R] * z[I] * 2;
		z[R] = tmp[R] + c[R];
		z[I] = tmp[I] + c[I];
	}
	return (-1);
}

int
	cr(int i)
{
	return ((i % 256) * (255 - (i % 256)) / 65);
}

void
	draw_mandelbrot(t_data *img)
{
	float		dx;
	float		dy;
	int			iy;
	int			ix;
	t_complex	c;

	dx = (XMAX - XMIN) / (double)SCREEN_W;
	dy = (YMAX - YMIN) / (double)SCREEN_H;
	iy = -1;
	while (++iy < SCREEN_H)
	{
		ix = -1;
		while (++ix < SCREEN_W)
		{
			float x = XMIN + dx * (double)ix;
			float y = YMIN + dy * (double)iy;

			c[R] = x;
			c[I] = y;
			int	i = include_mandelbrot_set(c);
			if (0 <= i)
			{
				// TODO: INT range
				// i += 51;
				my_mlx_pixel_put(img, ix, iy, get_color(cr(i * COLOR), cr(i * COLOR + COLOR_RANGE), cr(i * COLOR + COLOR_RANGE * 2)));
			}
		}
	}
}

void
	ft_draw(char **argv, t_data *img)
{
	if (!ft_strcmp(argv[1], ARG_M)
		|| !ft_strcmp(argv[1], ARG_MANDELBROT))
	{
		draw_mandelbrot(img);
	}
	else if (!ft_strcmp(argv[1], ARG_J)
		|| !ft_strcmp(argv[1], ARG_JULIA))
	{
		return ;
	}
}
