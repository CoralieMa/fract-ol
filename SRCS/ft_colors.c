/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:44:51 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/10 10:46:55 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, 0x00});
}

int	ft_gradien2(t_mlx *mlx, int iter, int i)
{
	int	color;
	int	pas;

	color = 0xff;
	pas = 0xff / ((ITER_MAX + mlx->fract->cpt) / 2);
	while (i != iter)
	{
		color -= pas;
		++i;
	}
	return (color);
}

int	ft_gradien1(t_mlx *mlx, int iter, int i)
{
	int	color;
	int	pas;

	color = 0x00;
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
		if (iter < (ITER_MAX + mlx->fract->cpt) / 2)
		{
			color = ft_gradien1(mlx, iter, 0);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0x20, color, 0x40));
		}
		else if (iter < ITER_MAX + mlx->fract->cpt)
		{
			color = ft_gradien2(mlx, iter, (ITER_MAX + mlx->fract->cpt) / 2);
			my_mlx_pixel_put(mlx->img, x, y, ft_trgb(0xff, 0xff, color));
		}
	}
	else if (iter == ITER_MAX + mlx->fract->cpt)
		my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
}
