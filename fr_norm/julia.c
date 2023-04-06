/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:15:01 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/06 12:50:17 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_data *data, char *x, char *y)
{
	data->zm = 1.0;
	data->x_mv = 0;
	data->y_mv = 0;
	data->width = 1200;
	data->height = 1000;
	data->color = 0xFF0000;
	data->zoom = 1;
	data->c_re = ft_atof(x);
	data->c_im = ft_atof(y);
	data->new_re = 0;
	data->new_im = 0;
	data->old_re = 0;
	data->old_im = 0;
	data->max_n = 100;
	julia(data);
}

int	julia_n(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_n && data->new_re * data->new_re
		+ data->new_im * data->new_im < 4)
	{
		data->old_re = data->new_re;
		data->old_im = data->new_im;
		data->new_re = data->old_re * data->old_re - data->old_im
			* data->old_im + data->c_re;
		data->new_im = 2 * data->old_re * data->old_im + data->c_im;
		i++;
	}
	return (i);
}

#include <stdio.h>

void	julia(t_data *data)
{
	int	x[3];

	printf("%f\n %f\n",data->c_re, data->c_im);
	x[2] = 0;
	x[1] = 100;
	ft_check_range(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xFFFFFF, "Julia");
	while (x[1] < data->height)
	{
		x[0] = 0;
		while (x[0] < data->width)
		{
			data->new_re = (1.5 * (x[0] - data->width / 2) / (0.3 * data->zoom
						* data->width)) + data->x_mv;
			data->new_im = ((x[1] - data->height / 2) / (0.3 * data->zoom
						* data->height)) + data->y_mv;
			x[2] = julia_n(data);
			if (x[2] < data->max_n)
				my_mlx_pixel_put(&data->img, x[0], x[1],
					(data->color * x[2] / 100));
			x[0]++;
		}
		x[1]++;
	}
}
