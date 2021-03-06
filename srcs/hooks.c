/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:02:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 22:08:48 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	show_help(t_fractol *fractol)
{
	printf("HELP\n"
		"  [ESC]         Exit.\n"
		"  [arrows]      Move.\n"
		"  [mouse wheel] Zoom.\n"
		"  [c]           Change color.\n"
		"  [h]           Show help.\n"
		"  [r]           Reset position.\n");
	if (fractol->type == TYPE_JULIA)
		printf(
			"  [shift]       And mouse position, transform the Julia-set.\n");
}

int
	ft_key_press(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		ft_exit(fractol, EXIT_SUCCESS);
	else if (key == KEY_UP || key == KEY_DOWN
		|| key == KEY_LEFT || key == KEY_RIGHT)
		ft_move(key, fractol);
	else if (key == KEY_C)
	{
		if (fractol->color_itr == 0)
			fractol->color_itr = 40;
		else if (fractol->color_itr == 40)
			fractol->color_itr = 150;
		else if (fractol->color_itr >= 170)
			fractol->color_itr = 0;
		else
			fractol->color_itr += 10;
	}
	else if (key == KEY_R)
		ft_reset(fractol);
	else if (key == KEY_H)
		show_help(fractol);
	else if (key == KEY_SHIFT)
		fractol->is_shift = TRUE;
	return (0);
}

int
	ft_key_release(int key, t_fractol *fractol)
{
	if (key == KEY_SHIFT)
		fractol->is_shift = FALSE;
	return (0);
}

int
	ft_mouse(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = fractol->min_real
		+ (fractol->max_real - fractol->min_real) * x / SCREEN_W;
	mouse_y = fractol->min_imgn
		+ (fractol->max_imgn - fractol->min_imgn) * y / SCREEN_H;
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
