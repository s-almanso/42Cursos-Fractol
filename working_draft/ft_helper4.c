/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:05:20 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/05 21:34:41 by salmanso         ###   ########.fr       */
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

double	ft_atof(const char *str)
{
	unsigned int	num;
	int			sign;
	int			i;
	int			flag;

	if (!str)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i] != '1' && str[i] != '2' && str[i] != '0')
		return (0);

	while ((str[i] > 47 && str[i] < 58 && str[i]) || str[i] == '.')
	{
		if (str[i] == '.' && str[i + 1] >= '1')
		{
			flag = 1;
			i++;
		}
		if (flag)
		{
			flag++;
		}
		num = (num * 10) + (str[i] - '0');
		if (num > 2147483648 && sign == -1)
			return(0);
		else if (num > 4294967295 && sign == 1)
			return(0);
		i++;
	}
	double a = pow(10, (flag - 1));
	double b = ((double) num * sign);
	return (b / a);
}
