/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:43:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/06 13:44:13 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "libft.h"
# include "fractol.h"
# include <unistd.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# define MAX_ITERATIONS		60

double		my_abs(double x);
t_complex	ship_squared(t_complex z1);
t_complex	ship_sum(t_complex z1, t_complex z2);
void		name_error_bonus(void);
void		ft_error_bonus(void);
int			valid_args_bonus(int ac, char **av, int is_valid);

#endif