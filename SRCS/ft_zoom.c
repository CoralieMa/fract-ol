/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:45:18 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:17:19 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static void	ft_fractal_zoom(t_mlx *mlx)
{
	if (ft_strncmp(mlx->fract->type, "julia", 10) == 0)
	{
		mlx->fract->x1 = -mlx->fract->zoom_t;
		mlx->fract->x2 = mlx->fract->zoom_t;
		mlx->fract->y1 = -1.2 * mlx->fract->zoom_t;
		mlx->fract->y2 = 1.2 * mlx->fract->zoom_t;
		ft_julia(mlx);
	}
	else
	{
		mlx->fract->a_x = 1.35 * mlx->fract->zoom_t;
		mlx->fract->a_y = 1.2 * mlx->fract->zoom_t;
		if (ft_strncmp(mlx->fract->type, "mandelbrot", 10) == 0)
			ft_mandelbrot(mlx);
		else if (ft_strncmp(mlx->fract->type, "burningship", 10) == 0)
			ft_burning_ship(mlx);
		else if (ft_strncmp(mlx->fract->type, "my_burningship", 10) == 0)
			ft_my_burning_ship(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
}

int	ft_zoom(int keycode, int x_m, int y_m, t_mlx *mlx)
{
	if (y_m >= 0 && x_m >= 0)
	{
		if (keycode == 5)
		{
			if (ITER_MAX + mlx->fract->cpt == 11)
				mlx->fract->zoom_t = 9.988723;
			mlx->fract->zoom_t *= 0.75;
			mlx->fract->cpt += 8;
			ft_fractal_zoom(mlx);
		}
		if (keycode == 4)
		{
			if (ITER_MAX + mlx->fract->cpt > 12)
				mlx->fract->cpt -= 8;
			mlx->fract->zoom_t /= 0.75;
			ft_fractal_zoom(mlx);
		}
	}
	return (0);
}
