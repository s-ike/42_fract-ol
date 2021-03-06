/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:10:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/14 23:39:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t
	get_color(t_complex z, t_complex c, t_fractol *fractol)
{
	int			i;
	double		tmp;
	const int	color_range = COLOR_RANGE + fractol->color_itr;

	i = -1;
	while (++i < fractol->itr_max && z[R] * z[R] + z[I] * z[I] <= 4.0)
	{
		tmp = z[R] * z[R] - z[I] * z[I] + c[R];
		if (fractol->type == TYPE_TRICORN)
			z[I] = -(z[R] * z[I]) * 2 + c[I];
		else
			z[I] = z[R] * z[I] * 2 + c[I];
		z[R] = tmp;
		if (fractol->type == TYPE_BURNING_SHIP)
		{
			z[R] = fabs(z[R]);
			z[I] = fabs(z[I]);
		}
	}
	if (i == fractol->itr_max)
		return (0);
	return (ft_rgb(
			ft_calc_color(i * COLOR_RATIO),
			ft_calc_color(i * COLOR_RATIO + color_range),
			ft_calc_color(i * COLOR_RATIO + color_range * 2)));
}

void
	my_mlx_pixel_put(t_mlximg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void
	draw_mandelbrot(t_fractol *fractol)
{
	int			iy;
	int			ix;
	t_complex	z;
	t_complex	c;
	t_complex	d;

	d[R] = (fractol->max_real - fractol->min_real) / (double)SCREEN_W;
	d[I] = (fractol->max_imgn - fractol->min_imgn) / (double)SCREEN_H;
	iy = -1;
	while (++iy < SCREEN_H)
	{
		ix = -1;
		while (++ix < SCREEN_W)
		{
			c[R] = fractol->min_real + d[R] * (double)ix;
			c[I] = fractol->min_imgn + d[I] * (double)iy;
			ft_bzero(&z, sizeof(t_complex));
			my_mlx_pixel_put(&fractol->img, ix, iy,
				get_color(z, c, fractol));
		}
	}
}

static void
	draw_julia(t_fractol *fractol)
{
	int			iy;
	int			ix;
	t_complex	z;
	t_complex	d;

	d[R] = (fractol->max_real - fractol->min_real) / (double)SCREEN_W;
	d[I] = (fractol->max_imgn - fractol->min_imgn) / (double)SCREEN_H;
	iy = -1;
	while (++iy < SCREEN_H)
	{
		ix = -1;
		while (++ix < SCREEN_W)
		{
			z[R] = fractol->min_real + d[R] * (double)ix;
			z[I] = fractol->min_imgn + d[I] * (double)iy;
			my_mlx_pixel_put(&fractol->img, ix, iy,
				get_color(z, fractol->julia_c, fractol));
		}
	}
}

void
	ft_draw(t_fractol *fractol)
{
	if (fractol->type == TYPE_MANDELBROT)
		draw_mandelbrot(fractol);
	else if (fractol->type == TYPE_JULIA)
		draw_julia(fractol);
	else if (fractol->type == TYPE_BURNING_SHIP)
		draw_mandelbrot(fractol);
	else if (fractol->type == TYPE_TRICORN)
		draw_mandelbrot(fractol);
}
