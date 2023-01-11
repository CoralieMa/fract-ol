/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:08:05 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/11 13:39:56 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fract_ol.h"

int	ft_exit(int code)
{
	if (code == 1)
		write(1, "Wrong parameter\n", 17);
	else if (code == 2 || code == 3)
		write(1, "Wrong number parameters\n", 25);
	else if (code == 4)
		write(1, "Malloc error\n", 14);
	exit(EXIT_SUCCESS);
}
