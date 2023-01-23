/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:27:57 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/18 14:28:09 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

char	*ft_str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1[i] || !s2[i]) && n != 0)
	{
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	}
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, 0x00});
}

void	ft_infos(void)
{
	write(1, "\n\nUse the mouse wheel to zoom\n", 30);
	write(1, "Press c -> gradient colors fractal\n", 36);
	write(1, "Press v -> basis colors fractal\n", 33);
	write(1, "Press b -> black & white fractal\n", 34);
	write(1, "Press the cross or escape to quit\n\n", 36);
}
