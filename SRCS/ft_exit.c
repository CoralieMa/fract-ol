/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:08:05 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:24:26 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static void	ft_arguments(void)
{
	write(1, "\nArguments to define fractal's type and/or set:\n\n", 50);
	write(1, "* Mandelbrot\n* Julia  real_number  imginary_number\n", 52);
	write(1, "* Burningship\n* My_burningship\n\n", 33);
	exit(EXIT_SUCCESS);
}

int	ft_exit(t_mlx *mlx, int code)
{
	if (code == 1)
		ft_arguments();
	if (code == 2)
	{
		write(1, "\nWrong number of argument\n", 27);
		write(1, "* Julia  real_number  imginary_number\n", 39);
	}
	else if (code == 3)
		write(1, "Malloc error\n", 14);
	free(mlx->fract);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->wind);
	exit(EXIT_SUCCESS);
}
