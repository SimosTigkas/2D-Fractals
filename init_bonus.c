/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:01:30 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/04 15:24:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol_bonus.h"

void	get_values(t_fractal	*fractal)
{
	fractal->escape_value = 4.0;
	fractal->iterations_def = 800;
	fractal->shift_x = -1.4186;
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
			fractal->name = av[1];
			fractal->julia_x = ft_atodbl(av[2]);
			fractal->julia_y = ft_atodbl(av[3]);
		}
		else if ((ac == 2) && !ft_strncmp(av[1], "burningship", 11))
		{
			fractal->iterations_def = MAX_ITERATIONS;
			fractal->name = av[1];
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