/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:36:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/05 17:46:29 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	zoom_in(t_fractal *f)
{
	f->zoom *= 3;
	fractal_render(f);
}

void	zoom_out(t_fractal *f)
{
	f->zoom /= 3;
	fractal_render(f);
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	(void)keydata;
	if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx_connection);
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_UP))
		fractal->shift_y -= 0.05;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_DOWN))
		fractal->shift_y += 0.05;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_LEFT))
		fractal->shift_x += 0.05;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_RIGHT))
		fractal->shift_x -= 0.05;
	fractal_render(fractal);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (ydelta > 0 || xdelta > 0)
		zoom_in(fractal);
	else if (ydelta < 0 || xdelta < 0)
		zoom_out(fractal);
	fractal_render(fractal);
}
