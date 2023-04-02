/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:35:31 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/01 18:15:01 by salmanso         ###   ########.fr       */
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
	txt = ft_strjoin("Number of iterations : ", nbr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, txt);
	ft_free(&txt);
	ft_free(&nbr);
}

int	exit_app()
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
