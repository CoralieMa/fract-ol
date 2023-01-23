/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:44:51 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:24:15 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static void	ft_put_colors_b_a_w(t_mlx *mlx, int x, int y, int iter)
{
	if (iter < ITER_MAX + mlx->fract->cpt)
		my_mlx_pixel_put(mlx->img, x, y, 0x00ffffff);
	else if (iter == ITER_MAX + mlx->fract->cpt)
		my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
}

static int	ft_colors_base(t_mlx *mlx, int iter, float cpt)
{
	if (iter < ITER_MAX * cpt)
		return (0x00ff0000);
	else if (iter < ITER_MAX * cpt * 2)
		return (0x00ffff00);
	else if (iter < ITER_MAX * cpt * 4)
		return (0x0000ff00);
	else if (iter < ITER_MAX * cpt * 6)
		return (0x0000ff45);
	else if (iter < ITER_MAX * cpt * 8)
		return (0x0000ff45);
	else if (iter < ITER_MAX * cpt * 10)
		return (0x0000ffff);
	else if (iter < ITER_MAX * cpt * 12)
		return (0x000000ff);
	else if (iter < ITER_MAX * cpt * 14)
		return (0x004500ff);
	else if (iter < ITER_MAX * cpt * 16)
		return (0x00ff00ff);
	else
		return (ft_colors_base(mlx, iter, cpt * 18));
}

static void	ft_put_colors_grad(t_mlx *mlx, int x, int y, int iter)
{	
	int	color;

	if (iter < ITER_MAX + mlx->fract->cpt)
	{
		color = ft_colors_grad(mlx, iter, 0.5);
		my_mlx_pixel_put(mlx->img, x, y, color);
	}
	else if (iter == ITER_MAX + mlx->fract->cpt)
		my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
}

static void	ft_put_colors_base(t_mlx *mlx, int x, int y, int iter)
{	
	int	color;

	if (iter < ITER_MAX + mlx->fract->cpt)
	{
		color = ft_colors_base(mlx, iter, 0.15);
		my_mlx_pixel_put(mlx->img, x, y, color);
	}
	else if (iter == ITER_MAX + mlx->fract->cpt)
		my_mlx_pixel_put(mlx->img, x, y, 0x00000000);
}

void	ft_put_colors(t_mlx *mlx, int x, int y, int iter)
{
	if (mlx->color == 1)
		ft_put_colors_grad(mlx, x, y, iter);
	if (mlx->color == 2)
		ft_put_colors_base(mlx, x, y, iter);
	if (mlx->color == 3)
		ft_put_colors_b_a_w(mlx, x, y, iter);
}
