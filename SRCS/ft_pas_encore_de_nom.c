/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pas_encore_de_nom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:24 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/20 11:50:27 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

void	ft_fractal2(t_mlx *mlx, t_fract fract)
{
	mlx->zoom *= 0.75;
	if (ft_strncmp(fract.type, "mandelbrot", 10) == 0)
		ft_mandelbrot(mlx, *mlx->fract, mlx->zoom);
	// if (ft_strncmp(fract.type, "newton", 10) == 0)
	// 	ft_newton(mlx, fract);
	// else if (ft_strncmp(fract.type, "julia", 5) == 0)
	// {
	// 	if (argc < 4)
	// 		printf("error argument\n");
	// 	else
	// 	{
	// 		fract.x1 = -1;
	// 		fract.x2 = 1;
	// 		fract.y1 = -1.2;
	// 		fract.y2 = 1.2;
	// 		fract.c_r = ft_atof(argv[2]);
	// 		fract.c_i = ft_atof(argv[3]);
	// 		ft_julia(mlx, fract);
	// 	}
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mlx->img->img, 0, 0);
}

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

int	ft_zoom(int button, int xm, int ym, t_mlx *mlx)
{
	(void)mlx;
	(void)button;
	printf("(%d, %d)\n", xm, ym);
	ft_fractal2(mlx, *mlx->fract);
	return (0);
}



void	ft_fractal(t_mlx *mlx, int argc, char **argv, float zoom)
{
	t_fract	fract;

	fract.type = ft_str_tolower(argv[1]);
	if (ft_strncmp(fract.type, "mandelbrot", 10) == 0)
	{
		fract.centrum_x = - 0.73;
		fract.centrum_y = 0;
		// fract.x1 = fract.centrum_x - 1.35 * zoom;
		// fract.x2 = fract.centrum_x + 1.35 * zoom;
		// fract.y1 = fract.centrum_y - 1.2 * zoom;
		// fract.y2 = fract.centrum_y + 1.2 * zoom;
		// fract.x_min = - 1.35;
		// fract.x_max = + 1.35;
		// fract.y_min = - 1.2;
		// fract.y_max = + 1.2;
		ft_mandelbrot(mlx, fract, zoom);
	}
	if (ft_strncmp(fract.type, "newton", 10) == 0)
	{
		ft_newton(mlx, fract);
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
	*mlx->fract = fract;
}
