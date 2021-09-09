/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:02:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 17:52:45 by sikeda           ###   ########.fr       */
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
	(void)x;
	(void)y;
	(void)fractol;
	if (button == MOUSE_ZOOM_IN)
		ft_putendl_fd("zoom in", STDOUT_FILENO);
	else if (button == MOUSE_ZOOM_OUT)
		ft_putendl_fd("zoom out", STDOUT_FILENO);
	return (0);
}

int
	ft_x_close(t_fractol *fractol)
{
	ft_exit(fractol, EXIT_SUCCESS);
	return (0);
}
