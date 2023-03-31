/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:07 by vmuradia          #+#    #+#             */
/*   Updated: 2023/04/01 00:06:53 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Zoom and dezoom mandelbrot
*/

void	ft_zoom(int x, int y, t_data *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x / (data->zoom * 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_n++;
	clear_display_img(data);
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x /
		(data->zoom / 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
	clear_display_img(data);

}

/*
** Using mouse to zoom and dezoom + increase/dicrease iterations
*/

void clear_display_img(t_data *data)
{
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	my_mlx_pixel_put(&data->img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

int		mouse_hook(int mousecode, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mousecode == 5 || mousecode == 2)
			ft_zoom(x, y, data);
		else if (mousecode == 4 || mousecode == 1)
			ft_dezoom(x, y, data);
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		// clear_display_img(data);
		mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	}
	else if (data->fractol == 1)
		zoom_julia(data, mousecode);
	put_text(data);
	if (data->fractol == 2)
	{
		if (mousecode == 2 || mousecode == 5)
			data->zoom *= 1.2;
		else if (mousecode == 4 || mousecode == 1)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		fern(data);
	}
	return (0);
}

void	zoom_julia(t_data *data, int mousecode)
{
	if (mousecode == 2 || mousecode == 5)
	{
		data->zoom *= 1.2;
		data->max_n++;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		data->zoom /= 1.2;
		data->max_n--;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	julia(data);
}

/*
** Change colors for all + exit. keys
*/

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
//	mlx_clear_window(data->mlx_ptr, data->win_ptr);
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
