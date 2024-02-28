/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:32:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/22 08:32:38 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <unistd.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	mlx_image_t	img;
	double		escape_value;
	int			iterations_defintion;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractal;

# define ERROR_MESSAGE "./fractol mandelbrot or ./fractol julia <v1> <v2>"
# define WIDTH		800
# define HEIGHT		800
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00FF
# define MAGENTA	0xFF00FFFF
# define CYAN		0x00FFFFFF
# define ORANGE		0xFFA500FF
# define PURPLE		0x660066FF
# define GRAY		0x808080FF
# define LIGHT_GRAY	0xD3D3D3FF
# define DARK_GRAY	0xA9A9A9FF

void	fractal_init(t_fractal	*fractal);
void	fractal_render(t_fractal	*fractal);

#endif