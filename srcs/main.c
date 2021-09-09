/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 18:01:06 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!ft_is_valid_args(argc, argv))
		ft_exit_with_usage();
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, SCREEN_W, SCREEN_H, PRG_NAME);
	fractol.img.img = mlx_new_image(fractol.mlx, SCREEN_W, SCREEN_H);
	fractol.img.addr = mlx_get_data_addr(
			fractol.img.img, &fractol.img.bits_per_pixel, &fractol.img.line_length, &fractol.img.endian);
	ft_draw(argv, &fractol.img);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img.img, 0, 0);
	mlx_hook(fractol.win, KEY_PRESS, 1L << KEY_PRESS_MASK, ft_key_press, &fractol);
	mlx_hook(fractol.win, BTN_PRESS, 1L << BTN_PRESS_MASK, ft_mouse, 0);
	mlx_hook(fractol.win, BTN_X, 1L << STRUCTURE_NOTIFY_MASK, ft_x_close, &fractol);
	mlx_loop(fractol.mlx);
	exit(EXIT_SUCCESS);
}
