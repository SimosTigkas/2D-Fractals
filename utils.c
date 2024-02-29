/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/29 16:42:27 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

double	ft_atodbl(double flg, double multiplier, char *str)
{
	int		i;
	double	n;

	i = 0.0;
	n = 0.0;
	if (str[i] == '-')
		multiplier -= 1.0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str)
	{
		if (str[i] == '.')
			flg = 1.0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (flg == 1.0)
				multiplier /= 10.00;
			n = (n * 10.00) + (str[i] - '0');
		}
		i++;
	}
	return (multiplier * n);
}

void	ft_error(void)
{
	ft_putendl_fd("Error: Invalid arguments", 2);
	ft_putendl_fd("Please use: ./fractol mandelbrot or", 2);
	ft_putendl_fd("Please use: ./fractol julia <x> <y>", 2);
	exit(EXIT_FAILURE);
}

int	is_inrange(double v)
{
	if (v >= -2.0 && v <= 2.0)
		return (1);
	else
		return (0);
}

void	check_val(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str)
	{
		if (str[i] == '.')
		{
			while (j < i)
			{
				if (str[j++] == '.')
					ft_error();
			}
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if ((i != 0) || !ft_is_digit(str[i + 1]))
				ft_error();
		}
		else if (!ft_isdigit(str[i++]))
			ft_error();
	}
	if (is_inrange(ft_atodbl(0.0, 0.0, str)) == 0)
		ft_error();
}
