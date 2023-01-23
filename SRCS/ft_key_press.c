/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:00 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/17 14:46:27 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_key_pressed(int key_code, t_mlx *mlx)
{
	if (key_code == 53)
		ft_exit(mlx, 0);
	else if (key_code == 8)
		mlx->color = 1;
	else if (key_code == 9)
		mlx->color = 2;
	else if (key_code == 11)
		mlx->color = 3;
	if (ft_strncmp(mlx->fract->type, "mandelbrot", 10) == 0)
		ft_mandelbrot(mlx);
	else if (ft_strncmp(mlx->fract->type, "julia", 5) == 0)
		ft_julia(mlx);
	else if (ft_strncmp(mlx->fract->type, "burningship", 12) == 0)
		ft_burning_ship(mlx);
	else if (ft_strncmp(mlx->fract->type, "my_burningship", 15) == 0)
		ft_my_burning_ship(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
	return (0);
}
