/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/11 14:04:12 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_fract	fract;

	if (argc < 2)
		ft_exit(3);
	ft_init_wind(&mlx);
	ft_init_img(&mlx);
	fract = ft_init_fract();
	mlx.fract = &fract;
	ft_fractal(&mlx, argc, argv);
	mlx_key_hook(mlx.wind, ft_key_pressed, mlx.wind);
	mlx_hook(mlx.wind, 17, 0, ft_exit, mlx.wind);
	mlx_mouse_hook(mlx.wind, ft_zoom, &mlx);
	mlx_loop(mlx.mlx);
}
