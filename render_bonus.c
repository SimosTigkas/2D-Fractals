/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:00:44 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/04 15:28:07 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol_bonus.h"

double	my_abs(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imgnry = fractal->julia_y;
		fractal->shift_x = 0.5;
		fractal->shift_y = 0.2;
	}
	else
	{
		c->real = z->real;
		c->imgnry = z->imgnry;
	}
}

void	pixel_handler(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.imgnry = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&z, &c, fractal);
	while (i < fractal->iterations_def)
	{
		if (!ft_strncmp(fractal->name, "burningship", 11))
			z = ship_sum(ship_squared(z), c);
		else
			z = complex_sum(complex_squared(z), c);
		if ((z.real * z.real) + (z.imgnry * z.imgnry) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_def);
			mlx_put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, MAGENTA_BURST);
}

void	fractal_render(t_fractal	*fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_handler(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

int	burning_ship(double x, double y)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	iterations = 0;
	real = x;
	imag = y;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + x;
		imag = 2.0 * my_abs(real * imag) + y;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}
