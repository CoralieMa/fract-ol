/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:15:30 by cmartino          #+#    #+#             */
/*   Updated: 2022/12/19 11:40:07 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

// static unsigned char	get_t(int trgb)
// {
// 	return (((unsigned char *)&trgb)[3]);
// }

// static unsigned char	get_r(int trgb)
// {
// 	return (((unsigned char *)&trgb)[2]);
// }

// static unsigned char	get_g(int trgb)
// {
// 	return (((unsigned char *)&trgb)[1]);
// }

// static unsigned char	get_b(int trgb)
// {
// 	return (((unsigned char *)&trgb)[0]);
// }

int	ft_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, 0x00});
}
