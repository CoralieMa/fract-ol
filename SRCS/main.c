/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:20 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/15 13:56:39 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"
#include <stdio.h>
#include "unistd.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (0);
	ft_init_wind(&mlx);
	ft_init_img(&mlx);
	ft_fractal(&mlx, argc, argv);
	mlx_key_hook(mlx.wind, ft_key_pressed, mlx.wind);
	mlx_hook(mlx.wind, 17, 0, ft_exit, mlx.wind);
	mlx_hook(mlx.wind, 4, 0, ft_test, &mlx);
	mlx_loop(mlx.mlx);
}