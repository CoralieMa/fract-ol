/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:56:20 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/20 11:50:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_calc_mandelbrot(t_fract fract, int x, int y)
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
		fract.r = (fract.r * fract.r) - (fract.i * fract.i) + fract.c_r;
		fract.i = 2 * fract.i * fract.temp + fract.c_i;
		++i;
	}
	return (i);
}

void	ft_mandelbrot(t_mlx *mlx, t_fract fract, float zoom)
{
	int	x;
	int	y;
	int	iter;

	// fract.x1 = -2.1;
	// fract.x2 = 0.6;
	// fract.y1 = -1.2;
	// fract.y2 = 1.2;
	// fract.x1 = fract.centrum_x - fract.x_min * zoom;
	// fract.x2 = fract.centrum_x + fract.x_max * zoom;
	// fract.y1 = fract.centrum_y - fract.y_min * zoom;
	// fract.y2 = fract.centrum_y + fract.y_max * zoom;
	fract.x1 = fract.centrum_x - 1.35 * zoom;
	fract.x2 = fract.centrum_x + 1.35 * zoom;
	fract.y1 = fract.centrum_y - 1.2 * zoom;
	fract.y2 = fract.centrum_y + 1.2 * zoom;
	fract.zoom_x = WIDTH / (fract.x2 - fract.x1);
	fract.zoom_y = HEIGHT / (fract.y2 - fract.y1);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_calc_mandelbrot(fract, x, y);
			ft_put_colors(mlx, x, y, iter);
			++y;
		}
		++x;
	}
}
