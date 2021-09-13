/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 12:57:45 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef LEAKS

void
	destructor(void)__attribute__((destructor));

void
	destructor(void)
{
	int		status;
	char	buf[50];

	snprintf(buf, 50, "leaks %d &> leaksout", getpid());
	status = system(buf);
	if (status)
		system("cat leaksout >&2");
}
#endif

static void
	show_usage(void)
{
	printf("usage: ./fractol [number]\n"
		"\n"
		"[%d] Mandelbrot\n"
		"[%d] Julia\n"
		"[%d] Burning Ship\n",
		TYPE_MANDELBROT, TYPE_JULIA, TYPE_BURNING_SHIP);
}

void
	ft_exit_with_usage(void)
{
	ft_putstr_fd(PRG_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(EINVAL), STDERR_FILENO);
	show_usage();
	exit(EXIT_FAILURE);
}

void
	ft_exit(t_fractol *fractol, int exit_status)
{
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->mlx)
		mlx_destroy_display(fractol->mlx);
	if (fractol->mlx)
		free(fractol->mlx);
	fractol->win = NULL;
	fractol->img.img = NULL;
	fractol->mlx = NULL;
	exit(exit_status);
}
