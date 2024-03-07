/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:34:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/06 11:39:03 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"


void	get_values(t_fractal	*fractal, int ac, char **av)
{
	fractal->escape_value = 4.0;
	fractal->iterations_def = 400;
	fractal->shift_x = -1.456;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.5;
	if ((ac == 4) && !ft_strcmp(av[1], "julia"))
	{
		fractal->julia_x = ft_atodbl(av[2], 1);
		fractal->julia_y = ft_atodbl(av[3], 1);
		fractal->shift_x = -0.085;
		fractal->shift_y = -0.065;
	}
}

void	fractal_init(t_fractal *fractal, int ac, char **av)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx_connection)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!(fractal->img))
		exit(EXIT_FAILURE);
	get_values(fractal, ac, av);
}
