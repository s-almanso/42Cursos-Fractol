/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/27 21:40:53 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// each fractol has a numb. assign, selct and init

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

void ft_free(char **str)
{
	if (str && *str)
	{
		free (*str);
		*str = (NULL);
	}
}

// iterations when zooming only
void put_txt(t_data *data)
{
	char	*txt;
	char	*nbr;

	nbr = ft_itoa(data->max_N);
	txt = ft_strjoin("Number of Iterations: ", nbr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xffffff, txt);
	ft_free(&txt);
	ft_free(&nbr);
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
		mlx_key_hook(data->win_ptr, keys, data);
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
