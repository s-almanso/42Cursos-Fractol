/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/30 22:34:41 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	select_fractol(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		data->fractol = 1;
		julia_init(data);
	}
	else if (ft_strcmp(argv[1], "Fern") == 0)
	{
		data->fractol = 2;
		fern_init(data);
	}
	else
	{
		ft_putendl("Error! Invalid input!");
		return (0);
	}
	return (1);
}

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

int	exit_app()
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 1000 || y >= 1000 || x <= -1000 || y <= -1000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *) malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "Fractol 42");
		data->img.img = mlx_new_image(data->mlx_ptr, 2000, 2000);
		data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
							&data->img.endian);
		if ((select_fractol(argv, data)) == 0)
			return (-1);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
		mlx_hook(data->win_ptr, 17, 0, exit_app, data);
		mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2)
		ft_putendl("Error! Too many args!");
	else
		ft_putendl("Error! Please select desired Fractol!");
	return (0);
}
