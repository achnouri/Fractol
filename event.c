/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:41:48 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 16:27:33 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_hanedl(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_window(data);
	else if (key == LEFT_KEY)
		data->x -= 0.5 * data->zoom;
	else if (key == RIGHT_KEY)
		data->x += 0.5 * data->zoom;
	else if (key == UP_KEY)
		data->y += 0.5 * data->zoom;
	else if (key == DOWN_KEY)
		data->y -= 0.5 * data->zoom;
	else if (key == SPACE_KEY)
	{
		data->zoom = 1;
		data->x = 0;
		data->y = 0;
		data->color = 0x000103;
	}
	else if (key == PLUS)
		data->iteration += 10;
	else if (key == MINUS)
		data->iteration -= 10;
	mlx_clear_window(data->mlx, data->win);
	render_fractal(data);
	return (0);
}

int	mouse_hanedl(int key, int x, int y, t_data *data)
{
	double	zoom;

	zoom = data->zoom;
	if (key == SCR_UP)
		data->zoom *= 1.1;
	else if (key == SCR_DOWN)
		data->zoom *= 0.9;
	else if (key == LEFT_CLICK)
		data->color += 10;
	else if (key == RIGHT_CLICK)
		data->lock_mouse = !data->lock_mouse;
	data->x += scale(x, -2, 2, WIDTH) * (zoom - data->zoom);
	data->y += scale(y, -2, 2, WIDTH) * (zoom - data->zoom);
	mlx_clear_window(data->mlx, data->win);
	render_fractal(data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->lock_mouse == 1)
		return (0);
	data->c.reel = scale(x, -2, 2, WIDTH);
	data->c.imag = scale(y, -2, 2, HEIGHT);
	mlx_clear_window(data->mlx, data->win);
	render_fractal(data);
	return (0);
}
