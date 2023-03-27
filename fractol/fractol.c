/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/26 14:32:09 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int select_fractol(char **argv, t_data *data)
{
	if(ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if	(ft_strcmp(argv[1], "Julia") == 0)
	{
		data->fractol = 0;
		// julia_init(data);
	}
	else if (ft_strcmp(argv[1], "Third fractol") == 0)
	{
		data->fractol = 0;
		// init third fractol
	}
	else
	{
		ft_putendl("Error! Invalid input!");
		return(0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data*) malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 900, 900, "Fractol 42");
		if ((select_fractol(argv, data)) == 0)
			return(-1);
		//mlx_key_hook(data->win_ptr, keys, data);
		//mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2)
		ft_putendl("Error! Too many args!");
	else
		ft_putendl("Error! Please select desired Fractol!");
	return (0);
}
