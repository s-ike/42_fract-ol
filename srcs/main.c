/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 23:13:08 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	main_loop(t_fractol *fractol)
{
	ft_draw(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}

int
	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (ft_is_valid_args(argc, argv) == FALSE)
		ft_exit_with_usage();
	if (ft_init_fractol(&fractol, argv[1]) == FALSE)
		ft_exit(&fractol, EXIT_FAILURE);
	mlx_loop_hook(fractol.mlx, main_loop, &fractol);
	mlx_hook(fractol.win, KEY_PRESS, 1L << KEY_PRESS_MASK, ft_key_press, &fractol);
	mlx_hook(fractol.win, BTN_PRESS, 1L << BTN_PRESS_MASK, ft_mouse, &fractol);
	mlx_hook(fractol.win, BTN_X, 1L << STRUCTURE_NOTIFY_MASK, ft_x_close, &fractol);
	mlx_loop(fractol.mlx);
	exit(EXIT_SUCCESS);
}
