/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/09 17:35:00 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	select_fractol(int argc, char **argv, t_data *data)
{
	if (argc == 2)
		init(argc, argv, data);
	else if (argc == 4 && (ft_strcmp(argv[1], "Julia") == 0))
	{
		if (ft_strcmp(argv[1], "Julia") == 0)
		{
			data->fractol = 1;
			julia_init(data, argv[2], argv[3]);
		}
	}
	else if (argc == 4 && (ft_strcmp(argv[1], "Julia") != 0))
	{
		ft_error(argc, argv);
		return (0);
	}
	else
	{
		ft_error(argc, argv);
		return (0);
	}
	return (1);
}

void	ft_error(int argc, char **argv)
{
	if (argc == 2 && ((ft_strcmp(argv[1], "Mandelbrot") != 0)
			&& (ft_strcmp(argv[1], "Fern") != 0)))
	{
		ft_putendl("Error! Invalid input!");
		ft_putendl("Options: ./fractol 'Mandelbrot' 'Fern' 'Julia c_re c_im");
	}
	if (argc > 4 || argc <= 1)
		ft_putendl("Error! Options: ./fractol 'Mandelbrot' 'Julia' 'Fern'");
	if (argc == 4 && (ft_strcmp(argv[1], "Julia") != 0))
	{
		ft_putendl("Error! Invalid input for Julia set!");
		ft_putendl("I/P: ./fractol 'Julia c_re c_im");
	}
	else
	{
		ft_putendl("Error! Invalid input!");
		ft_putendl("Options: ./fractol 'Mandelbrot' 'Fern' 'Julia c_re c_im");
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 1;
	if(argc >= 3)
	{
		while(argv[2][i] != '\0')
		{
			if(argv[2][i] >= '0' && argv[2][i] <= '9')
				exit(1);
			i++;
		}
		i = 1;
		while(argv[3][i] != '\0')
		{
			if(argv[3][i] >= '0' && argv[3][i] <= '9')
				exit(1);
			i++;
		}
	}
	if (argc >= 2 && argc <= 4)
	{
		data = (t_data *) malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1000, "Fractol 42");
		data->img.img = mlx_new_image(data->mlx_ptr, 1200, 1000);
		data->img.addr = mlx_get_data_addr(data->img.img,
				&data->img.bits_per_pixel, &data->img.line_length,
				&data->img.endian);
		if ((select_fractol(argc, argv, data)) == 0)
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
	else if (argc > 4 || argc <= 1)
		ft_error(argc, argv);
	return (0);
}
