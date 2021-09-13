/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:10:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 21:13:43 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	calc_color(int i)
{
	return ((i % 256) * (255 - (i % 256)) / 65);
}

static uint32_t
	get_color2(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	color;

	color = r;
	color <<= 8;
	color |= g;
	color <<= 8;
	color |= b;
	return (color);
}

uint32_t
	get_color(t_complex z, t_complex c, t_fractol *fractol, t_bool is_bship)
{
	int			i;
	int			color_range;
	t_complex	p;

	i = -1;
	while (++i < fractol->itr_max)
	{
		p[R] = z[R] * z[R];
		p[I] = z[I] * z[I];
		if (4.0 < p[R] + p[I])
			break ;
		z[I] = z[R] * z[I] * 2 + c[I];
		z[R] = p[R] - p[I] + c[R];
		if (is_bship == TRUE)
		{
			if (z[I] < 0)
				z[I] = -z[I];
			if (z[R] < 0)
				z[R] = -z[R];
		}
	}
	if (i == fractol->itr_max)
		return (0);
	color_range = (COLOR_RANGE + fractol->color_itr) % 1000;
	return (get_color2(
			calc_color(i * COLOR_RATIO),
			calc_color(i * COLOR_RATIO + color_range),
			calc_color(i * COLOR_RATIO + color_range * 2)));
}

void
	my_mlx_pixel_put(t_mlximg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void
	draw_mandelbrot(t_fractol *fractol, t_bool is_bship)
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
			my_mlx_pixel_put(&fractol->img, ix, iy, get_color(z, c, fractol, is_bship));
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
			my_mlx_pixel_put(&fractol->img, ix, iy, get_color(z, fractol->julia_c, fractol, FALSE));
		}
	}
}

void
	ft_draw(t_fractol *fractol)
{
	if (fractol->type == TYPE_MANDELBROT)
		draw_mandelbrot(fractol, FALSE);
	else if (fractol->type == TYPE_JULIA)
		draw_julia(fractol);
	else if (fractol->type == TYPE_BURNING_SHIP)
		draw_mandelbrot(fractol, TRUE);
}
