/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:22:35 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/29 18:25:53 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys(int keys, t_data *data)
{
	if (keys == 53)
		exit(1);
	else if (keys == 18)
		data->color = 0x00ff00;
	else if (keys == 19)
		data->color = 0x0ff69b4;
	else if (keys == 20)
		data->color = 0x0ffdab9;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	else if (data->fractol == 2)
		fern(data);
	return (0);
}

void	ft_zoom(int x, int y, t_data *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x / (data->zoom * 1.2));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_n++;
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x / (data->zoom / 1.2));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
}

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mouse_code == 5 || mouse_code == 2)
			ft_zoom(x, y, data);
		else if (mouse_code == 4 || mouse_code == 1)
			ft_dezoom(x, y, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mandelbrot(data);
	}
	if (data->fractol == 1)
		zoom_julia(data, mouse_code);
	put_txt(data);
	if (data->fractol == 2)
	{
		if (mouse_code == 5 || mouse_code == 2)
			data->zoom *= 1.2;
		else if (mouse_code == 4 || mouse_code == 1)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		fern(data);
	}
	return (0);
}

void	zoom_julia(t_data *data, int mouse_code)
{
	if (mouse_code == 5 || mouse_code == 2)
	{
		data->zoom *= 1.2;
		data->max_n++;
	}
	else if (mouse_code == 4 || mouse_code == 1)
	{
		data->zoom /= 1.2;
		data->max_n--;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	julia(data);
}
