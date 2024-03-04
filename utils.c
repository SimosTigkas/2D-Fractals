/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/04 12:06:46 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

double	ft_atodbl(char *str)
{
	double	number;
	int		signal;
	int		i;
	double	n;

	signal = 1;
	number = 0;
	n = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signal = -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0' )
		number = number * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		number = number + (str[i++] - '0') * 0.1 * n;
		n /= 10;
	}
	return ((number) * signal);
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

// void	check_val(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (str)
// 	{
// 		if (str[i] == '.')
// 		{
// 			while (j < i)
// 			{
// 				if (str[j++] == '.')
// 					ft_error();
// 			}
// 		}
// 		if (str[i] == '+' || str[i] == '-')
// 		{
// 			if ((i != 0) || (str[i + 1] < '0' && str[i + 1] > '9'))
// 				ft_error();
// 		}
// 		else if (str[i + 1] < '0' && str[i + 1] > '9')
// 			ft_error();
// 	}
// 	if (is_inrange(ft_atodbl(str)) == 0)
// 		ft_error();
// }
