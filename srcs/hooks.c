/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:02:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/10 01:11:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	ft_key_press(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		ft_exit(fractol, EXIT_SUCCESS);
	return (0);
}

int
	ft_mouse(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = fractol->min_real + (fractol->max_real - fractol->min_real) * x / SCREEN_W;
	mouse_y = fractol->min_imgn + (fractol->max_imgn - fractol->min_imgn) * y / SCREEN_H;
	if (button == MOUSE_ZOOM_IN)
		ft_zoom_in(fractol, mouse_x, mouse_y);
	else if (button == MOUSE_ZOOM_OUT)
		ft_zoom_out(fractol, mouse_x, mouse_y);
	return (0);
}

int
	ft_x_close(t_fractol *fractol)
{
	ft_exit(fractol, EXIT_SUCCESS);
	return (0);
}
