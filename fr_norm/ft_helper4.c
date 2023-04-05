/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:05:20 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/06 00:42:16 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrows(int key, t_data *data)
{
	if (key == 123)
		data->x_mv += 0.025;
	else if (key == 124)
		data->x_mv -= 0.025;
	else if (key == 125)
		data->y_mv -= 0.025;
	else if (key == 126)
		data->y_mv += 0.025;
	clear_display_img(data);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	if (data-> fractol == 0 || data ->fractol == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
		put_txt(data);
	}
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

double	ft_atof(const char *str)
{
	unsigned int	x[4];
	double			a;
	double			b;

	if (!str)
		return (0);
	x[0] = 0;
	x[1] = 1;
	x[2] = 0;
	x[3] = 0;
	a = 0.0;
	while ((str[x[2]] >= 9 && str[x[2]] <= 13) || str[x[2]] == 32)
		x[2]++;
	if (str[x[2]] == '-' || str[x[2]] == '+')
	{
		if (str[x[2]] == '-')
			x[1] = -x[1];
		x[2]++;
	}
	return (b = ft_atof_cont(str, x, a));
}

double	ft_atof_cont(const char *str, unsigned int x[4], double a)
{
	while ((str[x[2]] > 47 && str[x[2]] < 58 && str[x[2]]) || str[x[2]] == '.')
	{
		if (str[x[2]] == '.' && str[x[2] + 1] >= '1')
		{
			x[3] = 1;
			x[2]++;
		}
		if (x[3])
			x[3]++;
		x[0] = (x[0] * 10) + (str[x[2]] - '0');
		if (x[0] > 2147483648)
			return (0);
		else if (x[0] > 4294967295 && x[1] == 1)
			return (0);
		x[2]++;
	}
	if (x[3])
		a = pow(10, (x[3] - 1));
	else
		a = 1;
	return (((double) x[0] * x[1]) / a);
}
