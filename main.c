/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:47:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/21 18:47:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inlcudes/fractol.h"

int main(int ac, char **av)
{
    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
        || (ac == 4 ) && ft_strcmp(av[1], "julia", 5))
    {
        //todo
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}