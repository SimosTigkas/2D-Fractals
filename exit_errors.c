/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:35:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/07 10:23:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	arg_count_error(void)
{
	ft_putendl_fd("Error: Too few arguments", 2);
	ft_putendl_fd("Please use: ./fractol julia <x> <y>", 2);
}

int	check_julia(char **av)
{
	int		is_valid;
	double	num1;
	double	num2;

	is_valid = 1;
	num1 = ft_atodbl(av[2], 1);
	num2 = ft_atodbl(av[3], 1);
	if (num1 == -42.0 || num2 == -42.0)
		is_valid = 0;
	if (num1 < -2.0 || num1 > 2.0)
		is_valid = 0;
	if (num2 < -2.0 || num2 > 2.0)
		is_valid = 0;
	return (is_valid);
}

void	name_error(void)
{
	ft_putendl_fd("Error: Invalid fractal name", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot", 2);
	ft_putendl_fd(" or ./fractol burningship", 2);
}

void	ft_error(void)
{
	ft_putendl_fd("Error: Invalid arguments", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or", 2);
	ft_putstr_fd(" ./fractol julia <x> <y>", 2);
	ft_putendl_fd(" or ./fractol burningship", 2);
	exit(EXIT_FAILURE);
}

int	valid_args(int ac, char **av, int is_valid)
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
			name_error();
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
