/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:59:38 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/27 16:32:22 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_data *data)
{
	data->width = 960;
	data->height = 540;
	data->min_Re = -2.5;
	data->max_Re = 1;
	data->min_Im = -1;
	data->max_Im = 1;
	data->color = 0xd7afd7;
	data->zoom = 200;
	data->max_N = 100;
	mandelbrot(data);
}

// find numb of iterations for mandelbrot

int		find_n(double c_Re, double c_Im, double max_N)
{
	int		i;
	double	z_Re;
	double	z_Im;
	double	tmp;

	i = 0;
	z_Re = 0;
	z_Im = 0;
	while(i < max_N && (z_Re * z_Re + z_Im) < 4.0)
	{
		tmp = z_Re * z_Re - z_Im * z_Im + c_Re;
		z_Im = 2.0 * z_Re * z_Im + c_Im;
		z_Re = tmp;
		i++;
	}
	return (i);
}

double find_Re(int x, t_data *data)
{
	double range;

	range = data->max_Re - data->min_Re;
	return(x * (range / data->width) + data->min_Re);
}

double find_Im(int y, t_data *data)
{
	double	range;

	range = data->max_Im - data->min_Im;
	return(y * (range / data->height) + data->min_Im);
}

void mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		n;

	x = 100;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Mandelbrot Set");
	while(x < data->width)
	{
		while(y < data->height)
		{
			data->c_Re = find_Re(x, data);
			data->c_Im = find_Im(y, data);
			n = find_n(data->c_Re, data->c_Im, data->max_N);
			if (n == data->max_N)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n / 100));
			y++;
		}
		x++;
		y = 100;
	}
}
