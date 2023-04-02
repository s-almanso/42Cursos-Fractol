/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:59:38 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/02 19:00:57 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_data *data)
{
	data->width = 1200;
	data->height = 1000;
	data->min_re = -2.05;
	data->max_re = 1.2;
	data->min_im = -1.3;
	data->max_im = 1.2;
	data->color = 0x080000;
	data->zoom = 200;
	data->max_n = 100;
	mandelbrot(data);
}

int	find_n(double c_re, double c_im, double max_n)
{
	int			i;
	double		z_re;
	double		z_im;
	double		tmp;

	i = 0;
	z_re = 0;
	z_im = 0;
	while (i < max_n && z_re * z_re + z_im * z_im < 4.0)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	y = 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xFFFFFF,
		"Mandelbrot Set");
	while (x < data->width)
	{
		while (y < data->height)
		{
			data->c_re = find_re(x, data);
			data->c_im = find_im(y, data);
			n = find_n(data->c_re, data->c_im, data->max_n);
			if (n == data->max_n)
				my_mlx_pixel_put(&data->img, x, y, 0x000000);
			else
				my_mlx_pixel_put(&data->img, x, y,
					(data->color * n / 100));
			y++;
		}
		x++;
		y = 50;
	}
}

double	find_re(int x, t_data *data)
{
	double	range;

	range = data->max_re - data->min_re;
	return (x * (range / data->width) + data->min_re);
}

double	find_im(int y, t_data *data)
{
	double	range;

	range = data->max_im - data->min_im;
	return (y * (range / data->height) + data->min_im);
}
