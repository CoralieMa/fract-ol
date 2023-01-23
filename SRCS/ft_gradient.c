/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:07 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/17 15:01:56 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static int	ft_gradient(t_mlx *mlx, int iter, int i, int color)
{
	int	pas;

	(void)mlx;
	pas = 0xff / (ITER_MAX / 2);
	while (i != iter)
	{
		color += pas;
		++i;
	}
	return (color);
}

int	ft_colors_grad(t_mlx *mlx, int iter, float cpt)
{
	int	color;
	int	color_final;

	if (iter < ITER_MAX * cpt)
	{
		color = ft_gradient(mlx, iter, 0, 0x00);
		color_final = ft_trgb(0x20, color, 0x40);
	}
	else if (iter < ITER_MAX * cpt * 2)
	{
		color = ft_gradient(mlx, iter, 0, 0x00);
		color_final = ft_trgb(0x20, color, 0x40);
	}
	else if (iter < ITER_MAX * cpt * 4)
	{
		color = ft_gradient(mlx, iter, ITER_MAX / 2, 0x00);
		color_final = ft_trgb(0xff, 0xff, color);
	}
	else
		color_final = ft_colors_grad(mlx, iter, cpt * 16);
	return (color_final);
}
