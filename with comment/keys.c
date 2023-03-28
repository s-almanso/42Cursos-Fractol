/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:22:35 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/27 21:31:22 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* changing colors of fractal & exit key */

int	keys(int keys, t_data *data)
{
	if (keys == 53)
		exit(1);
	else if(keys == 18)
		data->color = 0x00ff00;
	else if (keys = 19)
		data->color = 0x0ff69b4;
	else if (keys = 20)
		data->color = 0x0ffdab9;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fractol == 0)
		mandelbrot(data);
	else if(data->fractol == 1)
		julia(data);
	else if (data->fractol == 2)
		fern(data);
	return (0);
}

/* zoom and dezoom in mandelbrot*/

void ft_zoom(int x, int y, t_data *data)
{
	data->min_Re = (x / data->zoom + data->min_Re) - (x / (data->zoom * 1.2));
	data->min_Im = (y / data->zoom + data->min_Im) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_N++;
}

void ft_dezoom(int x, int y, t_data *data)
{
	data->min_Re = (x / data->zoom + data->min_Re) - (x / (data->zoom / 1.2));
	data->min_Im = (y / data->zoom + data->min_Im) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_N--;
}

// Usng mouse to zoom and dezoom + increase/decrease iterations

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mouse_code == 5 || mouse_code == 2)
			ft_zoom(x, y, data);
		else if(mouse_code == 4 || mouse_code == 1)
			ft_dezoom(x, y, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mandelbrot(data);
	}
	else if (data->fractol == 1)
		zoom_julia(data, mouse_code);
	put_text(data);
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

void zoom_julia(t_data *data, int mouse_code)
{
		if (mouse_code == 5 || mouse_code == 2)
			data->zoom *= 1.2;
		else if (mouse_code == 4 || mouse_code == 1)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		julia(data);
}
