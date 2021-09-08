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

static int
	include_fractal_set(t_complex z, t_complex c)
{
	int			i;
	t_complex	p;

	i = -1;
	while (++i < LOOP)
	{
		p[R] = z[R] * z[R];
		p[I] = z[I] * z[I];
		if (4.0 < p[R] + p[I])
			return (i);
		z[I] = z[R] * z[I] * 2 + c[I];
		z[R] = p[R] - p[I] + c[R];
	}
	return (-1);
}

int
	cr(int i)
{
	return ((i % 256) * (255 - (i % 256)) / 65);
}

static void
	draw_mandelbrot(t_data *img)
{
	int			iy;
	int			ix;
	int			i;
	t_complex	z;
	t_complex	c;

	iy = -1;
	while (++iy < SCREEN_H)
	{
		ix = -1;
		while (++ix < SCREEN_W)
		{
			c[R] = XMIN + (XMAX - XMIN) / (double)SCREEN_W * (double)ix;
			c[I] = YMIN + (YMAX - YMIN) / (double)SCREEN_H * (double)iy;
			ft_bzero(&z, sizeof(t_complex));
			i = include_fractal_set(z, c);
			if (0 <= i)
			{
				// TODO: INT range
				// i += 51;
				my_mlx_pixel_put(img, ix, iy, get_color(cr(i * COLOR), cr(i * COLOR + COLOR_RANGE), cr(i * COLOR + COLOR_RANGE * 2)));
			}
		}
	}
}

static void
	draw_julia(t_data *img)
{
	int			iy;
	int			ix;
	int			i;
	t_complex	z;
	t_complex	c = {0.3, 0.63};

	iy = -1;
	while (++iy < SCREEN_H)
	{
		ix = -1;
		while (++ix < SCREEN_W)
		{
			z[R] = XMIN + (XMAX - XMIN) / (double)SCREEN_W * (double)ix;
			z[I] = YMIN + (YMAX - YMIN) / (double)SCREEN_H * (double)iy;
			i = include_fractal_set(z, c);
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
		draw_julia(img);
	}
}
