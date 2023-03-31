/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:09:35 by vmuradia          #+#    #+#             */
/*   Updated: 2023/03/31 01:35:35 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_data
{
	t_img_data	img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	double		minreal;
	double		maxreal;
	double		min_i;
	double		max_i;
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		max_n;
	int			random;
}				t_data;

/*
** main
*/

int				fract_select(char **argv, t_data *data);
void			put_text(t_data *data);
int				exit_app();
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void			clear_display_img(t_data *data);


/*
** mandelbrot
*/

void			mandelbrot_init(t_data *data);
int				find_n(double cr, double ci, double max_n);
void			mandelbrot(t_data *data);
double			find_real(int x, t_data *data);
double			find_imaginary(int y, t_data *data);

/*
** julia
*/

void			julia(t_data *data);
void			julia_init(t_data *data);
void			zoom_julia(t_data *data, int mousecode);
int				julia_n(t_data *data);

/*
** mouse and keys = buttons
*/

void			ft_zoom(int x, int y, t_data *data);
void			ft_dezoom(int x, int y, t_data *data);
int				keys(int key, t_data *data);
int				mouse_hook(int mousecode, int x, int y, t_data *data);

/*
** fern blya
*/

void			fern(t_data *data);
void			fern_init(t_data *data);
void			second_part(t_data *data);

#endif
