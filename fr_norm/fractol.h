/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:34 by salmanso          #+#    #+#             */
/*   Updated: 2023/04/06 12:55:22 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "./minilibx/mlx.h"

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_data
{
	t_img_data	img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	double		c_re;
	double		c_im;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		zoom;
	double		max_n;
	int			rand;
	double		zm;
	double		x_mv;
	double		y_mv;
}	t_data;

void	init(int argc, char **argv, t_data *data);
void	ft_free(char **str);
void	put_txt(t_data *data);
int		select_fractol(int argc, char **argv, t_data *data);
void	ft_error(int argc, char **argv);
int		exit_app(void);

void	mandelbrot_init(t_data *data);
double	find_im(int y, t_data *data);
double	find_re(int x, t_data *data);
int		find_n(double c_re, double c_im, double max_n);
void	mandelbrot(t_data *data);

void	julia_init(t_data *data, char *j, char *k);
int		julia_n(t_data *data);
void	julia(t_data *data);

void	fern_init(t_data *data);
void	fern_cont(t_data *data);
void	fern(t_data *data);

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		keys(int keys, t_data *data);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);
void	zoom_julia(t_data *data, int mouse_code);
void	clear_display_img(t_data *data);
void	zoom_fern(t_data *data, int mouse_code);
void	arrows(int key, t_data *data);
void	ft_color(int key, t_data *data);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(const char *str);
void	ft_check_range(t_data *data);
double	ft_atof_cont(const char *str, unsigned int x[4], double a, int sign);
void	zoom_mandelbrot(t_data *data, int mouse_code);

#endif
