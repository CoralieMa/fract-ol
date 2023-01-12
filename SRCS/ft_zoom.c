/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:45:18 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/12 15:07:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static void	ft_fractal_zoom(t_mlx *mlx)
{
	if (ft_strncmp(mlx->fract->type, "mandelbrot", 10) == 0)
	{
		mlx->fract->a_x = 1.35 * mlx->fract->zoomT;
		mlx->fract->a_y = 1.2 * mlx->fract->zoomT;
		ft_mandelbrot(mlx, mlx->fract->zoomT);
	}
	if (ft_strncmp(mlx->fract->type, "julia", 10) == 0)
	{
		mlx->fract->x1 = -mlx->fract->zoomT;
		mlx->fract->x2 = mlx->fract->zoomT;
		mlx->fract->y1 = -1.2 * mlx->fract->zoomT;
		mlx->fract->y2 = 1.2 * mlx->fract->zoomT;
		ft_julia(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
}

int	ft_zoom(int keycode, int x_m, int y_m, t_mlx *mlx)
{
	if (y_m >= 0 && x_m >= 0)
	{
		if (keycode == 5)
		{
			if (ITER_MAX + mlx->fract->cpt > 32)
				mlx->fract->zoomT *= 0.75;
			mlx->fract->zoomT *= 0.75;
			mlx->fract->cpt += 4;
			ft_fractal_zoom(mlx);
		}
		if (keycode == 4)
		{
			if (ITER_MAX + mlx->fract->cpt > 32)
				mlx->fract->cpt -= 4;
			mlx->fract->zoomT /= 0.75;
			ft_fractal_zoom(mlx);
		}
	}
	return (0);
}
