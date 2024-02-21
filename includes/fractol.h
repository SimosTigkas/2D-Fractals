/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:08:09 by marvin            #+#    #+#             */
/*   Updated: 2024/02/21 19:08:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //debugging
# include "includes/libft.h"
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

typedef struct s_complex
{
    double  real;
    double  imgnry;
}               t_complex;

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value1> <value2>\"






#endif