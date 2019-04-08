/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intpower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moriarty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:29:34 by moriarty          #+#    #+#             */
/*   Updated: 2019/02/18 22:40:34 by moriarty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intpower(int nb, int pow)
{
	if (!nb || pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	nb = nb * ft_intpower(nb, pow - 1);
	return (nb);
}
