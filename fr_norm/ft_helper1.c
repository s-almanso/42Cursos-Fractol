/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:33:45 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/06 00:19:56 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(int argc, char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "Fern") == 0)
	{
		data->fractol = 2;
		fern_init(data);
	}
	else
	{
		ft_error(argc, argv);
		exit_app();
	}
}

void	ft_check_range(t_data *data)
{
	if (data->c_re > 2.01 || data->c_re < -2.01)
	{
		ft_putendl("Error! Invalid Julia range!");
		exit_app();
	}
	if (data->c_im > 2.01 || data->c_im < -2.01)
	{
		ft_putendl("Error! Invalid Julia range!");
		exit_app();
	}
}
