/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:14 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/10 10:51:55 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_calc_julia(t_fract *fract, int x, int y)
{
	int		i;
	float	temp;

	fract->r = x / fract->zoom_x + fract->x1;
	fract->i = y / fract->zoom_y + fract->y1;
	i = 0;
	while ((fract->r * fract->r) + (fract->i * fract->i) < 4 && i < ITER_MAX)
	{
		temp = fract->r;
		fract->r = (fract->r * fract->r) - (fract->i * fract->i) + fract->c_r;
		fract->i = 2 * fract->i * temp + fract->c_i;
		++i;
	}
	return (i);
}

void	ft_julia(t_mlx *mlx)
{
	int	x;
	int	y;
	int	iter;

	mlx->fract->zoom_x = WIDTH / (mlx->fract->x2 - mlx->fract->x1);
	mlx->fract->zoom_y = HEIGHT / (mlx->fract->y2 - mlx->fract->y1);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_calc_julia(mlx->fract, x, y);
			ft_put_colors(mlx, x, y, iter);
			++y;
		}
		++x;
	}
}
