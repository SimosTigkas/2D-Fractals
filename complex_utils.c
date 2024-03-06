/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:39:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/06 13:39:49 by stigkas          ###   ########.fr       */
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
