/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:12:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/16 21:55:42 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	ft_zoom_in(t_fractol *fractol, double x, double y)
{
	float	tmp;

	if (fractol->max_real - fractol->min_real < MIN_RANGE
	|| fractol->max_imgn - fractol->min_imgn < MIN_RANGE)
		return ;
	fractol->max_real = x + (fractol->max_real - x) * ZOOM_RATIO;
	fractol->min_real = x + (fractol->min_real - x) * ZOOM_RATIO;
	fractol->max_imgn = y + (fractol->max_imgn - y) * ZOOM_RATIO;
	fractol->min_imgn = y + (fractol->min_imgn - y) * ZOOM_RATIO;
	tmp = (fractol->itr_base + 1.0) * ITR_RATIO;
	if ((int)tmp <= __INT_MAX__)
	{
		(fractol->itr_base)++;
		fractol->itr_max = (int)tmp;
	}
}

void
	ft_zoom_out(t_fractol *fractol, double x, double y)
{
	fractol->max_real = x + (fractol->max_real - x) * (1 / ZOOM_RATIO);
	fractol->min_real = x + (fractol->min_real - x) * (1 / ZOOM_RATIO);
	fractol->max_imgn = y + (fractol->max_imgn - y) * (1 / ZOOM_RATIO);
	fractol->min_imgn = y + (fractol->min_imgn - y) * (1 / ZOOM_RATIO);
	if (fractol->itr_base > ITR_BASE)
		(fractol->itr_base)--;
	fractol->itr_max = (int)(fractol->itr_base * ITR_RATIO);
}
