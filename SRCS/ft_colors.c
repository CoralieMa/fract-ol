/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:44:51 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/20 09:13:20 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

// void	ft_put_colors(t_mlx *mlx, int x, int y, int iter)
// {	
// 	if (iter < ITER_MAX)
// 	{
// 		if (iter < ITER_MAX / 8)
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0x00, 0x00));
// 		else if (iter < ITER_MAX / 4)
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0x40, 0x00));
// 		else if (iter < 3 * (ITER_MAX / 8))
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0x80, 0x00));
// 		else if (iter < ITER_MAX / 2)
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0xff, 0x00));
// 		else if (iter < 5 * (ITER_MAX / 8))
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x80, 0xff, 0x00));
// 		else if (iter < 3 * (ITER_MAX / 4))
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x40, 0xff, 0x00));
// 		else if (iter < 7 * (ITER_MAX / 8))
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x00, 0xff, 0x00));
// 		else if (iter < ITER_MAX)
// 			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x00, 0xff, 0x40));
// 	}
// }

int	ft_gradien2(int iter, int i)
{
	int color = 0xff;
	int	pas = 0xff / (ITER_MAX / 2);

	
	while(i != iter)
	{
		color -= pas;
		++i;
	}
	return (color);
}

int	ft_gradien1(int iter, int i)
{
	int color = 0x00;
	int	pas = 0xff / (ITER_MAX / 2);

	
	while(i != iter)
	{
		color += pas;
		++i;
	}
	return (color);
}

void	ft_put_colors(t_mlx *mlx, int x, int y, int iter)
{	
	if (iter < ITER_MAX)
	{
		if (iter < ITER_MAX / 2)
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x20, ft_gradien1(iter, 0), 0x40));
		else if (iter < ITER_MAX)
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0xff, ft_gradien2(iter, ITER_MAX / 2 )));
	}
	else if (iter == ITER_MAX)
			my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
}
