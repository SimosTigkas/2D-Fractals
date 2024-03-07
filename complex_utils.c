/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:39:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/07 10:30:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"


t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imgnry = z1.imgnry + z2.imgnry;
	return (res);
}

t_complex	complex_squared(t_complex z1)
{
	t_complex	res;

	res.real = (z1.real * z1.real) - (z1.imgnry * z1.imgnry);
	res.imgnry = 2 * z1.real * z1.imgnry;
	return (res);
}

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
