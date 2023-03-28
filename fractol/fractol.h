/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:34 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/28 20:24:58 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "./minilibx/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fractol;
	int		color;
	int		width;
	int		height;
	double	max_re;
	double	min_re;
	double	max_im;
	double	min_im;
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	max_n;
	int		rand;
}	t_data;

void	ft_putendl(char *s);
int		select_fractol(char **argv, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	ft_free(char **str);
void	put_txt(t_data *data);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_count_digits(int n);
char	*ft_itoa_conv(int n, char *str, int len);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

void	mandelbrot_init(t_data *data);
double	find_im(int y, t_data *data);
double	find_re(int x, t_data *data);
int		find_n(double c_re, double c_im, double max_n);
void	mandelbrot(t_data *data);

void	julia_init(t_data *data);
int		julia_n(t_data *data);
void	julia(t_data *data);

void	fern_init(t_data *data);
void	fern_cont(t_data *data);
void	fern(t_data *data);

int		keys(int keys, t_data *data);
void	ft_zoom(int x, int y, t_data *data);
void	ft_dezoom(int x, int y, t_data *data);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);
void	zoom_julia(t_data *data, int mouse_code);

#endif
