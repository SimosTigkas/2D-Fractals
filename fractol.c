/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:37:46 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/07 10:25:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!valid_args(ac, av, 0))
		exit(EXIT_FAILURE);
	if ((ac == 2) && !ft_strcmp(av[1], "mandelbrot"))
		fractal.name = av[1];
	else if ((ac == 4) && !ft_strcmp(av[1], "julia"))
		fractal.name = av[1];
	else if ((ac == 2) && !ft_strcmp(av[1], "burningship"))
	{
		fractal.iterations_def = MAX_ITERATIONS;
		fractal.name = av[1];
	}
	fractal_init(&fractal, ac, av);
	fractal_render(&fractal);
	mlx_key_hook(fractal.mlx_connection, ft_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx_connection, ft_scrollhook, &fractal);
	mlx_loop(fractal.mlx_connection);
	mlx_terminate(fractal.mlx_connection);
	return (EXIT_SUCCESS);
}
