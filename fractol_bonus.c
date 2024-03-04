/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:02:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/04 15:17:30 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol_bonus.h"

double	map(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (num) / (old_max) + new_min);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!valid_args(ac, av, &fractal))
		exit(EXIT_FAILURE);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_key_hook(fractal.mlx_connection, ft_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx_connection, ft_scrollhook, &fractal);
	mlx_loop(fractal.mlx_connection);
	mlx_terminate(fractal.mlx_connection);
	return (EXIT_SUCCESS);
}
