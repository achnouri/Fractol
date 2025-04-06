/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:24:06 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 08:26:51 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_data *data)
{
	data->color = 0x000103;
	data->iteration = 400;
	data->lock_mouse = 1;
	data->zoom = 1.0;
	data->x = 0.0;
	data->y = 0.0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data ->name_fractal);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian);
	mlx_key_hook(data->win, key_hanedl, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_mouse_hook(data->win, mouse_hanedl, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	valid_arg(ac, av, &data);
	data_init(&data);
	render_fractal(&data);
	mlx_loop(data.mlx);
}
