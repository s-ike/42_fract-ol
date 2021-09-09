/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:02:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 23:43:01 by sikeda           ###   ########.fr       */
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
#include <stdio.h>
int
	ft_mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)fractol;
	(void)x;
	(void)y;
	if (button == MOUSE_ZOOM_IN)
		ft_zoom_in(fractol);
	else if (button == MOUSE_ZOOM_OUT)
		ft_zoom_out(fractol);
	return (0);
}

int
	ft_x_close(t_fractol *fractol)
{
	ft_exit(fractol, EXIT_SUCCESS);
	return (0);
}
