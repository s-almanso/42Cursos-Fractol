/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:18:38 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/31 00:01:09 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fern_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->new_re = 0;
	data->old_re = 0;
	data->new_im = 0;
	data->old_im = 0;
	data->color = 0x008000;
	data->zoom = 1;
	fern(data);
}

void	fern_cont(t_data *data)
{
	if (data->rand >= 1 && data->rand <= 7)
	{
		data->new_re = -0.15 * data->old_re + 0.28 * \
				data->old_im * data->zoom;
		data->new_im = 0.26 * data->old_re + 0.24 * \
				data->old_im + 0.44 * data->zoom;
	}
	else if (data->rand >= 8 && data->rand <= 15)
	{
		data->new_re = 0.2 * data->old_re - 0.26 \
				* data->old_im * data->zoom;
		data->new_im = 0.23 * data->old_re + 0.22 \
				* data->old_im + 1.6 * data->zoom;
	}
	else
	{
		data->new_re = 0.85 * data->old_re + 0.04 \
				* data->old_im * data->zoom;
		data->new_im = -0.04 * data->old_re + 0.85 \
				* data->old_im + 1.6 * data->zoom;
	}
}

void	fern(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xFFFFFF, \
			"Barnsley Fern");
	data->max_n = 100000;
	while (data->max_n > 0)
	{
		data->rand = rand() % 100;
		if (data->rand == 0)
		{
			data->new_re = 0 * data->zoom;
			data->new_im = 0.16 * data->old_im * data->zoom;
		}
		else
			fern_cont(data);
		my_mlx_pixel_put(&data->img, 30 * data->new_re + \
			data->width / 2, 50 * data->new_im + data->height / 3, data->color);
		data->old_re = data->new_re;
		data->old_im = data->new_im;
		data->max_n--;
	}
}
