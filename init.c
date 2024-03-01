/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:34:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/01 14:52:02 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	get_values(t_fractal	*fractal)
{
	fractal->escape_value = 4.0;
	fractal->iterations_def = 400;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.2;
}

int	valid_args(int ac, char **av, t_fractal *fractal)
{
	if (ac > 1)
	{
		if ((ac == 2) && !ft_strncmp(av[1], "mandelbrot", 10))
			fractal->name = av[1];
		else if ((ac == 4) && !ft_strncmp(av[1], "julia", 5))
		{
			check_val(av[2]);
			check_val(av[3]);
			fractal->name = av[1];
			fractal->julia_x = ft_atodbl(0.0, 0.0, av[2]);
			fractal->julia_y = ft_atodbl(0.0, 0.0, av[3]);
		}
	}
	else
	{
		ft_error();
		return (0);
	}
	return (1);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx_connection)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!(fractal->img))
		exit(EXIT_FAILURE);
	get_values(fractal);
}
