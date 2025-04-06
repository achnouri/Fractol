/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:00:10 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 08:26:55 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_input(void)
{
	write(1, "____________help_______________\n", 32);
	write(1, "\n./fractol mandelbrot\n", 22);
	write(1, "\n./fractol julia 0.45 0.2 (between -2 and 2)\n", 45);
	write(1, "./fractol tricorn\n", 23);
	write(1, "______________________________\n", 32);
}

int	in_range(char *str)
{
	double	arg;
	size_t	i;

	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	if (str[i] == '\0')
		return (write(2, "Error\n", 7), exit(0), 0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_strlen(str) != i || !ft_strcmp(str, "")
		|| !ft_strcmp(str, "-") || !ft_strcmp(str, "+")
		|| !ft_strcmp(str, "-.") || !ft_strcmp(str, "+.")
		|| !ft_strcmp(str, "."))
		return (0);
	arg = ft_atod(str);
	return (-2 <= arg && arg <= 2);
}

void	valid_arg(int ac, char **av, t_data *data)
{
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0))
	{
		data->name_fractal = "mandelbrot";
		return ;
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0
		&& in_range(av[2]) && in_range(av[3]))
	{
		data->name_fractal = "julia";
		data->c.reel = ft_atod(av[2]);
		data->c.imag = ft_atod(av[3]);
		return ;
	}
	else if (ac == 2 && !ft_strcmp(av[1], "tricorn"))
	{
		data->name_fractal = "tricorn";
		return ;
	}
	help_input();
	exit(0);
}
