/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pas_encore_de_nom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:24 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/15 15:47:33 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_exit(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	ft_test(int button, int xm, int ym, t_mlx *mlx)
{
	(void)mlx;
	(void)button;
	printf("(%d, %d)\n", xm, ym);
	mlx->fract += 1;
	if (mlx->fract == 3)
		mlx->fract = 1;
	return (0);
}

void	ft_fractal(t_mlx *mlx, int argc, char **argv)
{
	t_fract	fract;

	(void)argc;
	fract.type = ft_str_tolower(argv[1]);
	if (ft_strncmp(fract.type, "mandelbrot", 10) == 0)
	{
		ft_mandelbrot(mlx, fract);
	}
	else if (ft_strncmp(fract.type, "julia", 5) == 0)
	{
		if (argc < 4)
			printf("error argument\n");
		else
		{
			fract.x1 = -1;
			fract.x2 = 1;
			fract.y1 = -1.2;
			fract.y2 = 1.2;
			fract.c_r = ft_atof(argv[2]);
			fract.c_i = ft_atof(argv[3]);
			ft_julia(mlx, fract);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
}
