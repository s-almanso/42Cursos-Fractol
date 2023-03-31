/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:51:26 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/31 23:58:17 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_free(char **str)
{
	if (str && *str)
	{
		free (*str);
		*str = (NULL);
	}
}

void	put_txt(t_data *data)
{
	char	*txt;
	char	*nbr;

	nbr = ft_itoa(data->max_n);
	txt = ft_strjoin("Number of Iterations: ", nbr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, txt);
	ft_free(&txt);
	ft_free(&nbr);
}

int		exit_app()
{
	exit(0);
	return (0);
}

void	clear_display_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
				&data->img.line_length, &data->img.endian);
	my_mlx_pixel_put(&data->img, 5, 5, 0x00FF0000);
}

void	zoom_fern(t_data *data, int mouse_code)
{
		if (mouse_code == 5 || mouse_code == 2)
		{
			data->zoom *= 1.2;
			clear_display_img(data);
		}
		else if (mouse_code == 4 || mouse_code == 1)
		{
			data->zoom /= 1.2;
			clear_display_img(data);
		}
		fern(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}
