/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 01:52:54 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	main(int argc, char **argv)
{
	t_fractol	flactol;

	if (!ft_is_valid_args(argc, argv))
		ft_exit_with_usage();
	flactol.mlx = mlx_init();
	flactol.win = mlx_new_window(flactol.mlx, SCREEN_W, SCREEN_H, PRG_NAME);
	flactol.img.img = mlx_new_image(flactol.mlx, SCREEN_W, SCREEN_H);
	flactol.img.addr = mlx_get_data_addr(
			flactol.img.img, &flactol.img.bits_per_pixel, &flactol.img.line_length, &flactol.img.endian);
	ft_draw(argv, &flactol.img);
	mlx_put_image_to_window(flactol.mlx, flactol.win, flactol.img.img, 0, 0);
	mlx_hook(flactol.win, KEY_PRESS, 1L << KEY_PRESS_MASK, ft_key_press, &flactol);
	mlx_hook(flactol.win, BTN_X, 1L << STRUCTURE_NOTIFY_MASK, ft_x_close, &flactol);
	mlx_loop(flactol.mlx);
	exit(EXIT_SUCCESS);
}
