/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:34 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/27 21:40:38 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "./minilibx/mlx.h"

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fractol;
	int		color;
	int		width;
	int		height;
	double	max_Re;
	double	min_Re;
	double	max_Im;
	double	min_Im;
	double	c_Re;
	double	c_Im;
	double	new_Re;
	double	new_Im;
	double	old_Re;
	double	old_Im;
	double	zoom;
	double	max_N;
	int		rand;
}	t_data;

void	ft_putendl(char *s);
int		select_fractol(char **argv, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	ft_free(char **str);


// Mandelbrot set
void	mandelbrot_init(t_data *data);
double	find_Im(int y, t_data *data);
double	find_Re(int x, t_data *data);
int		find_n(double c_Re, double c_Im, double max_N);
void	mandelbrot(t_data *data);

// Julia set
void julia_init(t_data *data);
int	julia_n(t_data *data);
void	julia(t_data *data);

// zoom and dezoom func

int		keys(int keys, t_data *data);
void	ft_zoom(int x, int y, t_data *data);
void	ft_dezoom(int x, int y, t_data *data);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);
void	zoom_julia(t_data *data, int mouse_code);


#endif
