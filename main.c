/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:33:05 by stigkas           #+#    #+#             */
/*   Updated: 2024/02/22 08:33:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inlcudes/fractol.h"

int     main(int ac, char **av)
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


test test