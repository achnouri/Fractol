/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:04:31 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 16:27:27 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int x, int y, t_data *data)
{
	int			iter;

	data->c.reel = scale(x, -2, 2, WIDTH) * data->zoom + data->x;
	data->c.imag = scale(y, -2, 2, HEIGHT) * data->zoom + data->y;
	data->z.reel = 0;
	data->z.imag = 0;
	iter = 0;
	while (iter < data->iteration)
	{
		data->z = sum(square_complex(data->z), data->c);
		if (mod(data->z) > 4)
			return (iter * data->color);
		iter++;
	}
	return (0);
}

int	tricorn(int x, int y, t_data *data)
{
	int	iter;

	data->c.reel = ((scale(x, -2, 2, WIDTH) * data->zoom + data->x) \
	* (scale(x, -2, 2, WIDTH) * data->zoom + data->x));
	data->c.imag = ((scale(y, -2, 2, HEIGHT) * data->zoom + data->y) \
	* (scale(y, -2, 2, HEIGHT) * data->zoom + data->y));
	data->z.reel = 0;
	data->z.imag = 0;
	iter = 0;
	while (iter < data->iteration)
	{
		data->z.imag = -data->z.imag;
		data->z = sum(square_complex(data->z), (data->c));
		if (mod(data->z) > 4)
			return (iter * data->color);
		iter++;
	}
	return (0);
}

int	julia(int x, int y, t_data *data)
{
	int	iter;

	data->z.reel = scale(x, -2, 2, WIDTH) * data->zoom + data->x;
	data->z.imag = scale(y, -2, 2, HEIGHT) * data->zoom + data->y;
	iter = 0;
	while (iter < data->iteration)
	{
		data->z = sum(square_complex(data->z), data->c);
		if (mod(data->z) > 4)
			return (iter * data->color);
		iter++;
	}
	return (0);
}

void	render_fractal(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	if (!data->name_fractal)
		return ;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strcmp(data->name_fractal, "mandelbrot"))
				color = mandelbrot(x, y, data);
			else if (!ft_strcmp(data->name_fractal, "julia"))
				color = julia(x, y, data);
			else if (!ft_strcmp(data->name_fractal, "tricorn"))
				color = tricorn(x, y, data);
			else
				return ;
			put_pixel(data, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
