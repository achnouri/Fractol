/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:08:22 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 08:26:59 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	int		signe;
	double	power;
	double	res;

	i = 0;
	res = 0;
	power = 1;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+' ))
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		power = power / 10;
		res = res + (str[i] - '0') * power;
		i++;
	}
	return (res * signe);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] || ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

double	scale(int value, double min, double max, double size)
{
	return (min + (max - min) * value / size);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*a;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	a = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)a = color;
}
