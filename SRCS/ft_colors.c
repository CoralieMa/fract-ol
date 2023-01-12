/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:44:51 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/12 16:47:01 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, 0x00});
}

int	ft_gradien(t_mlx *mlx, int iter, int i, int color)
{
	int	pas;

	(void)mlx;
	pas = 0xff / ((ITER_MAX + mlx->fract->cpt) / 2);
	while (i != iter)
	{
		color += pas;
		++i;
	}
	return (color);
}

void	ft_put_colors(t_mlx *mlx, int x, int y, int iter)
{	
	int	color;

	if (iter < ITER_MAX + mlx->fract->cpt)
	{
		if (iter < (ITER_MAX / 2))
		{
			color = ft_gradien(mlx, iter, 0, 0x00);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x20, color, 0x40));
		}
		else if (iter < ITER_MAX)
		{
			color = ft_gradien(mlx, iter, ITER_MAX / 2, 0xff);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0xff, color));
		}
		else if (iter < ITER_MAX + 16)
		{
			color = ft_gradien(mlx, iter, ITER_MAX / 2, 0x00);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0xff, color));
		}
		else if (iter < ITER_MAX + 32)
		{
			color = ft_gradien(mlx, iter, ITER_MAX / 2, 0xff);
			// printf("color = %d\n", color);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, color, 0x40));
		}
		else
		{
			my_mlx_pixel_put(mlx->img, x, y, 0x00ff0000);
		}
	}
	else if (iter == ITER_MAX + mlx->fract->cpt)
	{
		my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
	}
}
