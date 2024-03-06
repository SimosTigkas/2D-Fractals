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
# include <stdlib.h>

typedef struct s_complex
{
	double	real;
	double	imgnry;
}	t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	mlx_image_t	*img;
	double		escape_value;
	int			iterations_def;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractal;

# define WIDTH				600
# define HEIGHT				600
# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define YELLOW				0xFFFF00FF
# define MAGENTA			0xFF00FFFF
# define CYAN				0x00FFFFFF
# define ORANGE				0xFFA500FF
# define PURPLE				0x660066FF
# define GRAY				0x808080FF
# define LIGHT_GRAY			0xD3D3D3FF
# define DARK_GRAY			0xA9A9A9FF
# define MAGENTA_BURST   	0xFF00FF
# define AQUA_DREAM      	0x33CCCC
# define HOT_PINK        	0xFF66B2
# define ELECTRIC_BLUE   	0x0066FF

void		fractal_init(t_fractal *fractal, int ac, char **av);
void		fractal_render(t_fractal	*fractal);
void		ft_error(void);
int			valid_args(int ac, char **av, int is_valid);
double		ft_atodbl(char *str, double n);
t_complex	complex_sum(t_complex z1, t_complex z2);
t_complex	complex_squared(t_complex z1);
double		map(double num, double new_min, double new_max, double old_max);
void		ft_keyhook(mlx_key_data_t keydata, void *param);
void		ft_scrollhook(double xdelta, double ydelta, void *param);
void		zoom_in(t_fractal *f);
void		zoom_out(t_fractal *f);
int			check_julia(char **av);
void		get_values(t_fractal	*fractal, int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
void		name_error(void);
void		arg_count_error(void);

#endif