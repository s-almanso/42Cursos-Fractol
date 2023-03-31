/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:50 by vmuradia          #+#    #+#             */
/*   Updated: 2023/03/31 23:07:31 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Each fractal has a number. assign, select, init.
*/

int		fract_select(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractol = 1;
		julia_init(data);
	}
	else if (ft_strcmp(argv[1], "fern") == 0)
	{
		data->fractol = 2;
		fern_init(data);
	}
	else
	{
		ft_putendl("Usage: ./fractol [julia] or [mandelbrot] or [fern]");
		return (0);
	}
	return (1);
}

/*
** For iterations when zooming only
*/

void	put_text(t_data *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->max_n);
	text = ft_strjoin("Number of iterations : ", nb);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

int	exit_app()
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	// if (x >= 1000 || y >= 1000 || x <= -1000 || y <= -1000)
	// 	return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data*)malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1100, 1100, "My Fractol");
		data->img.img = mlx_new_image(data->mlx_ptr, 2000, 2000);
		data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
							&data->img.endian);
		if ((fract_select(argv, data)) == 0)
			return (-1);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
		mlx_key_hook(data->win_ptr, keys, data);
		mlx_hook(data->win_ptr, 17, 0, exit_app, data);
		mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2)
		ft_putendl("Too many arguments");
	else
		ft_putendl("Please specify the name of the fractol");
}
