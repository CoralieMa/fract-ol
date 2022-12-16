/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:07:12 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/15 13:02:41 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

// ***************************  NOTE : proteger atof ***************************

static float	ft_coma(char *str)
{
	float	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
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

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign *= ft_sign(str[i]);
		i++;
	}
	while (str[i] == '0')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i ++] - 48);
	if (str[i] == '.' || str[i] == ',')
		nb += ft_coma(&str[i] + 1);
	return (nb * sign);
}

// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	printf("%f\n", ft_atof(argv[argc - 1]));
// }
