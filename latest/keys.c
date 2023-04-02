/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:22:35 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/01 17:35:46 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_zoom(int x, int y, t_data *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x / (data->zoom * 1.2));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_n++;
	clear_display_img(data);
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x /
		(data->zoom / 1.2));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
	clear_display_img(data);
}

void clear_display_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	my_mlx_pixel_put(&data->img, 5, 5, 0x00FF0000);
}

int		mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mouse_code == 5 || mouse_code == 2)
			ft_zoom(x, y, data);
		else if (mouse_code == 4 || mouse_code == 1)
			ft_dezoom(x, y, data);
		mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	}
	else if (data->fractol == 1)
		zoom_julia(data, mouse_code);
	put_txt(data);
	if (data->fractol == 2)
		zoom_fern(data, mouse_code);
	return (0);
}

void	zoom_julia(t_data *data, int mouse_code)
{
	if (mouse_code == 2 || mouse_code == 5)
	{
		data->zoom *= 1.2;
		data->max_n++;
		clear_display_img(data);
	}
	else if (mouse_code == 4 || mouse_code == 1)
	{
		data->zoom /= 1.2;
		data->max_n--;
		clear_display_img(data);
	}
	julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

int		keys(int key, t_data *data)
{
	if (key == 53)
		exit(1);
	else if (key == 18)
		data->color = 0x00ff00;
	else if (key == 19)
		data->color = 0xff69b4;
	else if (key == 20)
		data->color = 0xffdab9;
	if (data->fractol == 0)
	{
		clear_display_img(data);
		mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, &data->img, 0, 0);
	}
	else if (data->fractol == 1)
		julia(data);
	else if (data->fractol == 2)
		fern(data);
	return (0);
}

void	zoom_fern(t_data *data, int mouse_code)
{
	if (mouse_code == 2 || mouse_code == 5)
		data->zoom *= 1.2;
	else if (mouse_code == 4 || mouse_code == 1)
		data->zoom /= 1.2;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	fern(data);
}
