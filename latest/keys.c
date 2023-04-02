/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:22:35 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/02 18:59:53 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	data->min_re = (x / data->zoom + data->min_re)
		- (x / (data->zoom / 1.2));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
	clear_display_img(data);
}

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mouse_code == 5 || mouse_code == 2)
			ft_zoom(x, y, data);
		else if (mouse_code == 4 || mouse_code == 1)
			ft_dezoom(x, y, data);
		mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
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

int	keys(int key)
{
	if (key == 53)
		exit(1);
	else if (key == 27)
		exit_app();
	return (0);
}
