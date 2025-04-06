/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:00:37 by achnouri          #+#    #+#             */
/*   Updated: 2025/03/22 16:27:15 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_complex
{
	double	reel;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void			*win;
	void			*mlx;
	char			*name_fractal;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	color;
	int				iteration;
	double			x;
	double			y;
	double			zoom;
	int				lock_mouse;
	t_complex		c;
	t_complex		z;
}				t_data;

# define HEIGHT 600
# define WIDTH 600

# define ESC_KEY  53
# define UP_KEY  126
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125	
# define SPACE_KEY 49
# define PLUS 0
# define MINUS 6

# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCR_UP 4
# define SCR_DOWN 5

t_complex	sum(t_complex	a, t_complex	b);
double		mod(t_complex z);
t_complex	square_complex(t_complex z);

double		ft_atod(char *str);
void		valid_arg(int ac, char **av, t_data *data);
size_t		ft_strlen(char *str);
int			in_range(char *str);
int			ft_strcmp(const char *s1, const char *s2);
double		ft_atod(char *str);
int			mandelbrot(int x, int y, t_data *data);
int			julia(int x, int y, t_data *data);
int			tricorn(int x, int y, t_data *data);
void		render_fractal(t_data *data);
double		scale(int value, double min, double max, double size);
void		put_pixel(t_data *data, int x, int y, int color);
int			mouse_move(int x, int y, t_data *data);

int			key_hanedl(int key, t_data *data);
int			close_window(t_data *data);
int			key_hanedl(int key, t_data *data);
int			mouse_hanedl(int key, int x, int y, t_data *data);

#endif