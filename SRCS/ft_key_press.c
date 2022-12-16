/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:00 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/21 15:28:58 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_key_pressed(int key_code, void *param)
{
	(void)param;
	if (key_code == 53) //esc
		exit(EXIT_SUCCESS);
	return (0);
}
