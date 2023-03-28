#include "fractol.h"

void julia_init(t_data *data)
{
	data->width = 960;
	data->height = 540;
	data->new_Re = 0;
	data->old_Re = 0;
	data->new_Im = 0;
	data->old_Im = 0;
	data->c_Re = -0.7;
	data->c_Im = 0.27015;
	data->color = 0x006600;
	data->zoom = 1;
	data->max_N = 200;
	mandelbrot(data);
}

// number of iterations

int	julia_n(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_N && data->new_Re * data->new_Re + data->new_Im * data->new_Im <4)
	{
		data->old_Re = data->new_Re;
		data->old_Im = data->new_Im;
		data->new_Re = data->old_Re * data->old_Re - data->old_Im * data->old_Im + data->c_Re;
		data->new_Im = 2 * data->old_Re * data->old_Im + data->c_Im;
		i++;
	}
	return (i);
}

void	julia(t_data *data)
{
	int x;
	int y;
	int n;

	x = 100;
	y = 100;
	n = 0;
	mlx_string_put(data->mlx_ptr, data->mlx_win, 500, 40, 0xffffff, "Julia");
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->new_Re = 1.5 * (x - data->width / 2) / (0.3 * data->zoom * data->width);
			data->new_Im = (y - data->height / 2) / (0.3 * data->zoom * data->height);
			if (n < data->max_N)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (data->color * n /100));
			x++;
		}
		y++;
		x = 100;
	}

}
