/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/23 16:28:11 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	ft_reset(t_fractol *fractol)
{
	fractol->max_real = MAX_REAL;
	fractol->min_real = MIN_REAL;
	fractol->max_imgn = MAX_IMGN;
	fractol->min_imgn = MIN_IMGN;
	fractol->itr_base = ITR_BASE;
	fractol->itr_max = (int)(fractol->itr_base * ITR_RATIO);
	fractol->julia_c[R] = JURIA_C_R;
	fractol->julia_c[I] = JURIA_C_I;
}

t_bool
	ft_init_fractol(t_fractol *fractol, int argc, char **argv)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (FALSE);
	fractol->win = mlx_new_window(fractol->mlx, SCREEN_W, SCREEN_H, PRG_NAME);
	if (!fractol->win)
		return (FALSE);
	fractol->img.img = mlx_new_image(fractol->mlx, SCREEN_W, SCREEN_H);
	if (!fractol->img.img)
		return (FALSE);
	fractol->img.addr = mlx_get_data_addr(
			fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	fractol->type = ft_atoi(argv[1]);
	fractol->is_shift = FALSE;
	ft_reset(fractol);
	if (fractol->type == TYPE_JULIA && 3 <= argc)
		fractol->julia_c[R] = ft_atof(argv[2]);
	if (fractol->type == TYPE_JULIA && 4 <= argc)
		fractol->julia_c[I] = ft_atof(argv[3]);
	return (TRUE);
}
