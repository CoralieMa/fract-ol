/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:56:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/12 14:52:25 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_calc_mandelbrot(t_fract *fract, int x, int y)
{
	int		i;
	float	temp;

	fract->c_r = x / fract->zoom_x + fract->x1;
	fract->c_i = y / fract->zoom_y + fract->y1;
	fract->r = 0;
	fract->i = 0;
	i = 0;
	while ((fract->r * fract->r) + (fract->i * fract->i) < 4 && i < ITER_MAX + fract->cpt)
	{
		temp = fract->r;
		fract->r = (fract->r * fract->r) - (fract->i * fract->i) + fract->c_r;
		fract->i = 2 * fract->i * temp + fract->c_i;
		++i;
	}
	return (i);
}

void	ft_mandelbrot(t_mlx *mlx, float zoom)
{
	int	x;
	int	y;
	int	iter;

	(void) zoom;
	mlx->fract->x1 = mlx->fract->centrum_x - mlx->fract->a_x ;
	mlx->fract->x2 = mlx->fract->centrum_x + mlx->fract->a_x ;
	mlx->fract->y1 = mlx->fract->centrum_y - mlx->fract->a_y ;
	mlx->fract->y2 = mlx->fract->centrum_y + mlx->fract->a_y ;
	mlx->fract->zoom_x = WIDTH / (mlx->fract->x2 - mlx->fract->x1);
	mlx->fract->zoom_y = HEIGHT / (mlx->fract->y2 - mlx->fract->y1);
	x = 0;
	printf("iter max = %d\n", ITER_MAX + mlx->fract->cpt);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_calc_mandelbrot(mlx->fract, x, y);
			ft_put_colors(mlx, x, y, iter);
			++y;
		}
		++x;
	}
}
