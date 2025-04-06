/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:18:10 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 16:27:40 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum(t_complex	a, t_complex	b)
{
	t_complex	res;

	res.reel = a.reel + b.reel;
	res.imag = a.imag + b.imag;
	return (res);
}

double	mod(t_complex z)
{
	return (((z.reel * z.reel) + (z.imag * z.imag)));
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.reel = z.reel * z.reel - z.imag * z.imag;
	res.imag = 2 * z.reel * z.imag;
	return (res);
}
