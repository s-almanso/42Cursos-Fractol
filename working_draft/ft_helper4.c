/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:05:20 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/04 22:15:25 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrows(int key, t_data *data)
{
	if (key == 123)
		data->x_mv += 0.025;
	else if(key == 124)
		data->x_mv -= 0.025;
	else if(key == 125)
		data->y_mv -= 0.025;
	else if(key == 126)
		data->y_mv += 0.025;
	clear_display_img(data);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	put_txt(data);
	if (data-> fractol == 0 || data ->fractol == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
}

void	ft_color(int key, t_data *data)
{
	if (key == 18)
		data->color = 0xe84a5f;
	else if (key == 19)
		data->color = 0xced8f9;
	else if (key == 20)
		data->color = 0xa10e0c;
	clear_display_img(data);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	put_txt(data);
	if (data-> fractol == 0 || data ->fractol == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
}
