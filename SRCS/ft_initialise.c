/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:48:56 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:16:04 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

void	ft_init_wind(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->wind = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx->color = 1;
	mlx->fract = malloc(sizeof(t_fract) * 1);
	if (!mlx->fract)
		ft_exit(mlx, 3);
	mlx->img = NULL;
}

void	ft_init_img(t_mlx *mlx)
{
	t_data	*img;

	img = malloc(sizeof(*img));
	if (!img)
		ft_exit(mlx, 3);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->img = img;
}

void	ft_init_fract(t_fract *fract)
{
	fract->x1 = 0;
	fract->x2 = 0;
	fract->y1 = 0;
	fract->y2 = 0;
	fract->r = 0;
	fract->i = 0;
	fract->zoom_x = 0;
	fract->zoom_y = 0;
	fract->zoom_t = 1;
	fract->c_r = 0;
	fract->c_i = 0;
	fract->centrum_x = 0;
	fract->centrum_y = 0;
	fract->a_x = 0;
	fract->a_y = 0;
	fract->cpt = 0;
	fract->type = NULL;
}
