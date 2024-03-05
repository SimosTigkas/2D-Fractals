/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/05 17:00:21 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

double	ft_atodbl(char *str, double n)
{
	double	number;
	int		signal;
	int		i;

	signal = 1;
	number = 0.0;
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
	if (str[i] != '\0')
		return (-42.0);
	return ((number) * signal);
}

double	map(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (num) / (old_max) + new_min);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
