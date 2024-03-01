/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:36:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/01 15:15:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	zoom_in(int x, int y, t_fractal *f)
{
	double	scale;

	scale = 4.0;
	scale = f->fparam.scale * f->zoom;
	f->fparam.xr = ((double)x / f->fparam.scale + f->fparam.xr) \
									-(double)x / scale;
	f->fparam.yi = ((double)y / f->fparam.scale + f->fparam.yi) \
									-(double)y / scale;
	f->fparam.scale += 2;
}

void	zoom_out(int x, int y, t_fractal *f)
{
	double	scale;

	scale = 4.0;
	scale = f->fparam.scale * f->zoom;
	f->fparam.xr = ((double)x / f->fparam.scale + f->fparam.xr) \
									-(double)x / scale;
	f->fparam.yi = ((double)y / f->fparam.scale + f->fparam.yi) \
									-(double)y / scale;
	f->fparam.scale -= 2;
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	(void)keydata;
	if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx_connection);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = param;
	x = 0;
	y = 0;
	if (ydelta > 0 || xdelta > 0)
		zoom_in(x, y, fractal);
	else if (ydelta < 0 || xdelta < 0)
		zoom_out(x, y, fractal);
	fractal->fparam.height = 0;
	fractal->fparam.width = 0;
	fractal_render(fractal);
}
