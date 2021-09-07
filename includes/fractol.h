#ifndef FLACTOL_H
# define FLACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include "libft.h"
# include "t_bool.h"
# ifdef LINUX
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx_mms_20200219/mlx.h"
# endif

# define PRG_NAME "fractol"
# define SCREEN_W 800
# define SCREEN_H 800
# define LOOP 20
# define COLOR 9
# define COLOR_RANGE 85

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

#endif
