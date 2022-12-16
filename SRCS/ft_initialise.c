/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:48:56 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/15 14:19:29 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

void	ft_init_wind(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->wind = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx->fract = 1;
}

void	ft_init_img(t_mlx *mlx)
{
	t_data	*img;

	img = malloc(sizeof(*img));
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
	mlx->img = img;
}
