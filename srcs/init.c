/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 07:42:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool
	ft_init_fractol(t_fractol *fractol, int type)
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
	fractol->max_real = MAX_REAL;
	fractol->min_real = MIN_REAL;
	fractol->max_imgn = MAX_IMGN;
	fractol->min_imgn = MIN_IMGN;
	fractol->type = type;
	fractol->itr_base = ITR_BASE;
	fractol->itr_max = (int)(fractol->itr_base * ITR_RATIO);
	return (TRUE);
}
