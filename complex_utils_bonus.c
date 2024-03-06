/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:09:56 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/06 13:39:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol_bonus.h"

t_complex	ship_squared(t_complex z)
{
	t_complex	res;

	res.real = my_abs(my_abs(z.real * z.real) - my_abs(z.imgnry * z.imgnry));
	res.imgnry = 2 * my_abs((z.real * z.imgnry));
	return (res);
}

t_complex	ship_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = my_abs(z1.real + z2.real);
	res.imgnry = my_abs(z1.imgnry - z2.imgnry);
	return (res);
}
