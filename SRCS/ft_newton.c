#include "../Includes/fract_ol.h"

int	ft_calc_newton(t_fract fract, int x, int y)
{
	int	i;

	fract.c_r = x / fract.zoom_x + fract.x1;
	fract.c_i = y / fract.zoom_y + fract.y1;
	fract.r = 0;
	fract.i = 0;
	i = 0;
	while ((fract.r * fract.r) + (fract.i * fract.i) < 4 && i < ITER_MAX)
	{
		fract.temp = fract.r;
		fract.r = fract.r * fract.r * fract.r - 3 * fract.r * fract.i * fract.i + fract.c_r - 1;
		fract.i = 3 * fract.temp * fract.temp * fract.i + fract.i * fract.i * fract.i + fract.c_i;
		++i;
	}
	return (i);
}

void	ft_newton(t_mlx *mlx, t_fract fract)
{
	int	x;
	int	y;
	int	iter;

	fract.x1 = -0.2;
	fract.x2 = 2.2;
	fract.y1 = -0.5;
	fract.y2 = 0.5;
	fract.zoom_x = WIDTH / (fract.x2 - fract.x1);
	fract.zoom_y = HEIGHT / (fract.y2 - fract.y1);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_calc_newton(fract, x, y);
			ft_put_colors(mlx, x, y, iter);
			++y;
		}
		++x;
	}
}