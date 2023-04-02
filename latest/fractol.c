/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/02 18:39:32 by salmanso         ###   ########.fr       */
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
		ft_putendl("Options: ./fractol 'Mandelbrot' 'Julia' 'Fern'");
		return (0);
	}
	return (1);
}

void	ft_error(int argc)
{
	if (argc > 2)
	{
		ft_putendl("Error! Please select desired Fractol!");
		ft_putendl("Options: ./fractol 'Mandelbrot' 'Julia' 'Fern'");
	}
	else if (argc <= 1)
		ft_putendl("Error! Options: ./fractol 'Mandelbrot' 'Julia' 'Fern'");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *) malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1000, "Fractol 42");
		data->img.img = mlx_new_image(data->mlx_ptr, 1200, 1000);
		data->img.addr = mlx_get_data_addr(data->img.img,
				&data->img.bits_per_pixel, &data->img.line_length,
				&data->img.endian);
		if ((select_fractol(argv, data)) == 0)
			return (-1);
		if (data-> fractol == 0 || data ->fractol == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.img, 0, 0);
		mlx_key_hook(data->win_ptr, keys, data);
		mlx_hook(data->win_ptr, 17, 0, exit_app, data);
		mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2 || argc <= 1)
		ft_error(argc);
	return (0);
}
