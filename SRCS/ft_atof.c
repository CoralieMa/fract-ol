/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:07:12 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/17 14:59:17 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

static float	ft_coma(t_mlx *mlx, char *str)
{
	float	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		ft_exit(mlx, 1);
	while (i > 0)
		nb = nb / 10 + (str[--i] - 48);
	return (nb / 10);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	ft_pre_atof(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

float	ft_atof(t_mlx *mlx, char *str)
{
	float	nb;
	int		i;
	int		j;
	int		sign;

	sign = 1;
	nb = 0;
	i = ft_pre_atof(str);
	while (str[i] == '-' || str[i] == '+')
	{
		sign *= ft_sign(str[i]);
		i++;
	}
	while (str[i] == '0')
		i ++;
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i ++] - 48);
	if (i - j > 9)
		ft_exit(mlx, 1);
	if (str[i] == '.' || str[i] == ',')
		nb += ft_coma(mlx, &str[i] + 1);
	else if (str[i])
		ft_exit(mlx, 1);
	return (nb * sign);
}
