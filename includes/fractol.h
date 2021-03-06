/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:46 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/23 15:54:09 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "key_map.h"
# include "t_bool.h"
# include "../minilibx-linux/mlx.h"

# define PRG_NAME "fractol"

# define SCREEN_W 800
# define SCREEN_H 800

# define ITR_BASE 50
# define ITR_RATIO 1.1
# define COLOR_RATIO 9
# define COLOR_RANGE 85

# define ZOOM_RATIO 0.9
# define MOVE_RATIO 0.01

# define NUM_MIN -2.0
# define MIN_REAL NUM_MIN
# define MIN_IMGN NUM_MIN
# define NUM_MAX 2.0
# define MAX_REAL NUM_MAX
# define MAX_IMGN NUM_MAX

# define MIN_RANGE 0.0000000000000025

# define JURIA_C_R 0.4
# define JURIA_C_I -0.325

# define R 0
# define I 1

enum e_type
{
	TYPE_START,
	TYPE_MANDELBROT,
	TYPE_JULIA,
	TYPE_BURNING_SHIP,
	TYPE_TRICORN,
	TYPE_END
};

typedef double	t_complex[2];

typedef struct s_mlximg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlximg;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_mlximg	img;
	t_complex	julia_c;
	double		min_real;
	double		max_real;
	double		min_imgn;
	double		max_imgn;
	int			itr_base;
	int			itr_max;
	int			color_itr;
	int			type;
	t_bool		is_shift;
}	t_fractol;

/* color.c */
int			ft_calc_color(int i);
uint32_t	ft_rgb(uint8_t r, uint8_t g, uint8_t b);
/* draw.c */
void		ft_draw(t_fractol *fractol);
/* exit.c */
void		ft_exit_with_usage(void);
void		ft_exit(t_fractol *fractol, int exit_status);
/* hooks.c */
int			ft_key_press(int key, t_fractol *fractol);
int			ft_key_release(int key, t_fractol *fractol);
int			ft_mouse(int button, int x, int y, t_fractol *fractol);
int			ft_x_close(t_fractol *fractol);
/* init.c */
void		ft_reset(t_fractol *fractol);
t_bool		ft_init_fractol(t_fractol *fractol, int argc, char **argv);
/* move.c */
void		ft_move(int key, t_fractol *fractol);
/* utils.c */
double		ft_atof(const char *str);
/* validator.c */
t_bool		ft_is_valid_args(int argc, char **argv);
/* zoom.c */
void		ft_zoom_in(t_fractol *fractol, double x, double y);
void		ft_zoom_out(t_fractol *fractol, double x, double y);

#endif
