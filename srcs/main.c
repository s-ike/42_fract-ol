#include "flactol.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void
	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_bool
	include_mandelbrot_set(t_complex c)
{
    t_complex z;
	t_complex p;
	t_complex tmp;

	z[R] = 0.0;
	z[I] = 0.0;
	for (int i = 0; i < 20; i++)
	{
		p[R] = z[R] * z[R];
		p[I] = z[I] * z[I];
		if (4.0 < p[R] + p[I])
			return (FALSE);
		tmp[R] = p[R] - p[I];
		tmp[I] = z[R] * z[I] * 2;
		z[R] = tmp[R] + c[R];
		z[I] = tmp[I] + c[I];
	}
	return (TRUE);
}

void
	draw_mandelbrot(t_data *img)
{
	float xmin = -2.0;
	float ymin = -2.0;
	float xmax = 2.0;
	float ymax = 2.0;
	float dx = (xmax - xmin) / (double)SCREEN_W;
	float dy = (ymax - ymin) / (double)SCREEN_H;

	for (int iy = 0; iy < SCREEN_H; iy++)
	{
		for (int ix = 0; ix < SCREEN_W; ix++)
		{
			float x = xmin + dx*(double)ix;
			float y = ymin + dy*(double)iy;
			t_complex c;
			c[R] = x;
			c[I] = y;
			if (include_mandelbrot_set(c)) {
				my_mlx_pixel_put(img, ix, iy, 0x00FF0000);
			}
		}
	}
}

int
	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_W, SCREEN_H, PRG_NAME);
	img.img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(
		img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	draw_mandelbrot(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
