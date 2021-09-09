#include "fractol.h"

void
	ft_zoom_in(t_fractol *fractol)
{
	fractol->max_real = 1 / ZOOM_RATIO * fractol->max_real;
	fractol->min_real = 1 / ZOOM_RATIO * fractol->min_real;
	fractol->max_imgn = 1 / ZOOM_RATIO * fractol->max_imgn;
	fractol->min_imgn = 1 / ZOOM_RATIO * fractol->min_imgn;
}

void
	ft_zoom_out(t_fractol *fractol)
{
	fractol->max_real = ZOOM_RATIO * fractol->max_real;
	fractol->min_real = ZOOM_RATIO * fractol->min_real;
	fractol->max_imgn = ZOOM_RATIO * fractol->max_imgn;
	fractol->min_imgn = ZOOM_RATIO * fractol->min_imgn;
}
