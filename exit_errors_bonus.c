/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:45:45 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/06 13:43:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol_bonus.h"

void	name_error_bonus(void)
{
	ft_putendl_fd("Error: Invalid fractal name", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot", 2);
	ft_putendl_fd(" or ./fractol burningship", 2);
}

void	ft_error_bonus(void)
{
	ft_putendl_fd("Error: Invalid arguments", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or", 2);
	ft_putstr_fd(" ./fractol julia <x> <y>", 2);
	ft_putendl_fd(" or ./fractol burningship", 2);
	exit(EXIT_FAILURE);
}

int	valid_args_bonus(int ac, char **av, int is_valid)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "julia"))
			arg_count_error();
		else if (!ft_strcmp(av[1], "mandelbrot"))
			is_valid = 1;
		else if (!ft_strcmp(av[1], "burningship"))
			is_valid = 1;
		else
			name_error_bonus();
	}
	else if (ac == 4)
	{
		if (!ft_strcmp(av[1], "julia") && (check_julia(av)))
			return (1);
		else if (!ft_strcmp(av[1], "julia") && (!check_julia(av)))
			ft_putendl_fd("Use -2 <= arguments <= 2", 2);
		else
			ft_putendl_fd("Please use: ./fractol julia <x> <y>", 2);
	}
	else
		ft_error();
	return (is_valid);
}
