/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 07:56:55 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/11 12:39:07 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	ft_move(int key, t_fractol *fractol)
{
	const double	x_move =
		(fractol->max_real - fractol->min_real) * MOVE_RATIO;
	const double	y_move =
		(fractol->max_imgn - fractol->min_imgn) * MOVE_RATIO;

	if (key == KEY_LEFT)
	{
		fractol->max_real -= x_move;
		fractol->min_real -= x_move;
	}
	else if (key == KEY_RIGHT)
	{
		fractol->max_real += x_move;
		fractol->min_real += x_move;
	}
	else if (key == KEY_UP)
	{
		fractol->max_imgn -= y_move;
		fractol->min_imgn -= y_move;
	}
	else if (key == KEY_DOWN)
	{
		fractol->max_imgn += y_move;
		fractol->min_imgn += y_move;
	}
}
