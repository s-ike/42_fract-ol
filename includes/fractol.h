/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:46 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/08 15:53:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "t_bool.h"
# ifdef LINUX
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx_mms_20200219/mlx.h"
# endif

# define PRG_NAME "fractol"

# define MSG_USAGE "usage: "
# define MSG_USAGE_ARGS "[mj]"

# define ARG_M "m"
# define ARG_MANDELBROT "mandelbrot"
# define ARG_J "j"
# define ARG_JULIA "julia"

# define SCREEN_W 800
# define SCREEN_H 800

# define LOOP 20
# define COLOR 9
# define COLOR_RANGE 85

# define NUM_MIN -2.0
# define XMIN NUM_MIN
# define YMIN NUM_MIN
# define NUM_MAX 2.0
# define XMAX NUM_MAX
# define YMAX NUM_MAX

# define R 0
# define I 1

typedef float	t_complex[2];

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* draw.c */
void	ft_draw(char **argv, t_data *img);
/* exit.c */
void	ft_exit_with_usage(void);
/* validator.c */
t_bool	ft_is_valid_args(int argc, char **argv);

#endif
