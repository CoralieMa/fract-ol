/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:55:16 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/10 10:18:05 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static void	ft_init_mandelbrot(t_mlx *mlx)
{
	mlx->fract->centrum_x = -0.75;
	mlx->fract->centrum_y = 0;
	mlx->fract->a_x = 1.35;
	mlx->fract->a_y = 1.2;
	ft_mandelbrot(mlx, 1);
}

static void	ft_init_julia(t_mlx *mlx, char **argv)
{
	mlx->fract->x1 = -1;
	mlx->fract->x2 = 1;
	mlx->fract->y1 = -1.2;
	mlx->fract->y2 = 1.2;
	mlx->fract->c_r = ft_atof(argv[2]);
	mlx->fract->c_i = ft_atof(argv[3]);
	ft_julia(mlx);
}

void	ft_fractal(t_mlx *mlx, int argc, char **argv)
{
	(void) argc;
	mlx->fract->type = ft_str_tolower(argv[1]);
	if (ft_strncmp(mlx->fract->type, "mandelbrot", 10) == 0)
		ft_init_mandelbrot(mlx);
	else if (ft_strncmp(mlx->fract->type, "julia", 5) == 0)
	{
		if (argc < 4)
			printf("error argument\n");
		else
			ft_init_julia(mlx, argv);
	}
	else
		printf("error argument\n");
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
}
