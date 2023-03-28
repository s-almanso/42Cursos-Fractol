/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:18:38 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/28 15:18:38 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fern_init(t_data *data)
{
	data->width = 960;
	data->height = 540;
	data->new_Re = 0;
	data->old_Re = 0;
	data->new_Im = 0;
	data->old_Im = 0;
	data->color = 0x00ff00;
	data->zoom = 1;
	fern(data);
}

void fern_cont(t_data *data)
{
	if (data->rand >= 1 && data->rand <= 7)
	{
		data->new_Re = -0.15 * data->old_Re + 0.28 * data->old_Im * data->zoom
		data->new_Im = 0.26 * data->old_Re + 0.24 *data->old_Im + 0.44 * data->zoom;
	}
	else if (data->rand >= 8 && data->rand <= 15)
	{
		data->new_Re = 0.2 * data->old_Re + 0.26 * data->old_Im * data->zoom
		data->new_Im = 0.23 * data->old_Re + 0.22 *data->old_Im + 1.6 * data->zoom;
	}
	else
	{
		data->new_Re = 0.85 * data->old_Re + 0.04 * data->old_Im * data->zoom
		data->new_Im = -0.04 * data->old_Re + 0.85 *data->old_Im + 1.6 * data->zoom;
	}
}

void fern(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Barnsley Fern");
	data->max_N = 10000;
	while(data->max_N > 0)
	{
		data->rand = rand() % 100;
		if (data->rand == 0)
		{
			data->new_Re = 0 * data->zoom;
			data->new_Im = 0.16 * data->old_Im * data->zoom;
		}
		else
			fern_cont(data);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 30 * data->new_Re + data->width / 2, 50 * data->new_Im + data->height / 3, data->color);
		data->old_Re = data->new_Re;
		data->old_Im = data->old_Im;
		data->max_N--;
	}
}
