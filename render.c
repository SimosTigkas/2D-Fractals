/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:57:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/01 14:38:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		c->real = z->real;
		c->imgnry = z->imgnry;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imgnry = fractal->julia_y;
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
		z = complex_sum(complex_squared(z), c);
		if ((z.real * z.real) + (z.imgnry * z.imgnry) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_def);
			mlx_put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, PURPLE);
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
