/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/07 23:34:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	*(unsigned int*)dst = color;
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
	float	xmin = -2.0;
	float	ymin = -2.0;
	float	xmax = 2.0;
	float	ymax = 2.0;
	float	dx = (xmax - xmin) / (double)SCREEN_W;
	float	dy = (ymax - ymin) / (double)SCREEN_H;

	for (int iy = 0; iy < SCREEN_H; iy++)
	{
		for (int ix = 0; ix < SCREEN_W; ix++)
		{
			float x = xmin + dx*(double)ix;
			float y = ymin + dy*(double)iy;
			t_complex c;
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

int
	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (!ft_is_valid_args(argc, argv))
		ft_exit_with_usage();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_W, SCREEN_H, PRG_NAME);
	img.img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_mandelbrot(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	exit(EXIT_SUCCESS);
}
