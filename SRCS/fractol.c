/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/17 14:13:31 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	ft_infos();
	if (argc < 2)
		ft_exit(&mlx, 1);
	ft_init_wind(&mlx);
	ft_init_img(&mlx);
	ft_init_fract(mlx.fract);
	ft_fractal(&mlx, argc, argv);
	mlx_key_hook(mlx.wind, ft_key_pressed, &mlx);
	mlx_hook(mlx.wind, 17, 0, ft_exit, &mlx);
	mlx_mouse_hook(mlx.wind, ft_zoom, &mlx);
	mlx_loop(mlx.mlx);
}
