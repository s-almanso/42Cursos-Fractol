/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:15:01 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/29 19:59:11 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->new_re = 0;
	data->old_re = 0;
	data->new_im = 0;
	data->old_im = 0;
	data->c_re = -0.12;
	data->c_im = 0.75;
	data->color = 0xFF00FF;
	data->zoom = 1;
	data->max_n = 300;
	julia(data);
}

int	julia_n(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_n && data->new_re * data->new_re \
		+ data->new_im * data->new_im < 4)
	{
		data->old_re = data->new_re;
		data->old_im = data->new_im;
		data->new_re = data->old_re * data->old_re \
			- data->old_im * data->old_im + data->c_re;
		data->new_im = 2 * data->old_re * data->old_im + data->c_im;
		i++;
	}
	return (i);
}

void	julia(t_data *data)
{
	int	x;
	int	y;
	int	n;

	x = 100;
	y = 100;
	n = 0;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xFFFFFF, "Julia");
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->new_re = 1.5 * (x - data->width / 2) \
					/ (0.3 * data->zoom * data->width);
			data->new_im = (y - data->height / 2) \
					/ (0.3 * data->zoom * data->height);
			n = julia_n(data);
			if (n < data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, \
						y, (data->color * n / 100));
			x++;
		}
		y++;
		x = 100;
	}
}
