/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_burning_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:05:23 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:25:06 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static int	ft_calc_my_burning_ship(t_fract *fract, int x, int y)
{
	int		i;
	int		iter;
	float	temp;

	fract->c_r = x / fract->zoom_x + fract->x1;
	fract->c_i = y / fract->zoom_y + fract->y1;
	fract->r = 0;
	fract->i = 0;
	i = 0;
	iter = ITER_MAX + fract->cpt;
	while ((fract->r * fract->r) + (fract->i * fract->i) < 4 && i < iter)
	{
		temp = fract->r;
		fract->r = (fract->r * fract->r) - (fract->i * fract->i) + fract->c_r;
		fract->i = fabs(2 * fract->i * temp + fract->c_i);
		++i;
	}
	return (i);
}

void	ft_my_burning_ship(t_mlx *mlx)
{
	int	x;
	int	y;
	int	iter;

	mlx->fract->x1 = mlx->fract->centrum_x - mlx->fract->a_x ;
	mlx->fract->x2 = mlx->fract->centrum_x + mlx->fract->a_x ;
	mlx->fract->y1 = mlx->fract->centrum_y - mlx->fract->a_y ;
	mlx->fract->y2 = mlx->fract->centrum_y + mlx->fract->a_y ;
	mlx->fract->zoom_x = WIDTH / (mlx->fract->x2 - mlx->fract->x1);
	mlx->fract->zoom_y = HEIGHT / (mlx->fract->y2 - mlx->fract->y1);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_calc_my_burning_ship(mlx->fract, x, y);
			ft_put_colors(mlx, x, y, iter);
			++y;
		}
		++x;
	}
}
