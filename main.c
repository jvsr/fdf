/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 13:16:44 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 12:29:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"

void	init_print(t_printline *print, t_mlx_data *mlx_data, int i0, int i1)
{
	print->dx = ft_abs(mlx_data->pixels->x[i1] - mlx_data->pixels->x[i0]);
	print->dy = ft_abs(mlx_data->pixels->y[i1] - mlx_data->pixels->y[i0]);
	print->xi = mlx_data->pixels->x[i0] < mlx_data->pixels->x[i1] ? 1 : -1;
	print->yi = mlx_data->pixels->y[i0] < mlx_data->pixels->y[i1] ? 1 : -1;
	print->p = print->dx - print->dy;
	print->p2 = 0;
	print->x = mlx_data->pixels->x[i0] + mlx_data->offset_x;
	print->y = mlx_data->pixels->y[i0] + mlx_data->offset_y;
}

void	printline(t_mlx_data *mlx_data, int i0, int i1)
{
	t_printline	print;

	init_print(&print, mlx_data, i0, i1);
	while (print.x != mlx_data->pixels->x[i1] + mlx_data->offset_x\
		|| print.y != mlx_data->pixels->y[i1] + mlx_data->offset_y)
	{
		mlx_pixel_put(MLX_PTR, WIN_PTR, print.x, print.y, mlx_data->color);
		if ((print.p2 = print.p * 2) > -print.dy)
		{
			print.p -= print.dy;
			print.x += print.xi;
		}
		if (print.p2 < print.dx)
		{
			print.p += print.dx;
			print.y += print.yi;
		}
	}
}

void	connect_dots(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while (i < mlx_data->x * mlx_data->y)
	{
		if (i % mlx_data->x != mlx_data->x - 1\
			&& check_if_in_screen(mlx_data, i, i + 1))
			printline(mlx_data, i, i + 1);
		if (i / mlx_data->x != mlx_data->y - 1\
			&& check_if_in_screen(mlx_data, i, i + mlx_data->x))
			printline(mlx_data, i, i + mlx_data->x);
		i++;
	}
}

int		key_press(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (!ISO && (keycode == 12 || keycode == 13 || keycode == 84\
				|| keycode == 86 || keycode == 88 || keycode == 91))
		set_axis_key_press(keycode, mlx_data);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		set_bias_key_press(keycode, mlx_data);
	if (keycode == 27 || keycode == 24 || keycode == 78 || keycode == 69)
		set_zoom_key_press(keycode, mlx_data);
	if (keycode == 34)
		set_iso_key_press(mlx_data);
	if (!ISO && keycode == 15)
		set_reset_key_press(mlx_data);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21\
		|| keycode == 23 || keycode == 22 || keycode == 26 || keycode == 28)
		set_color_key_press(keycode, mlx_data);
	set_init_offset(mlx_data);
	connect_dots(mlx_data);
	draw_menu(mlx_data);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx_data	*mlx_data;

	if (ac != 2)
		print_usage();
	mlx_data = init_mlx_data(av);
	rotate_all_axis(mlx_data);
	set_init_offset(mlx_data);
	connect_dots(mlx_data);
	draw_menu(mlx_data);
	mlx_hook(WIN_PTR, 2, 2, key_press, mlx_data);
	mlx_loop(MLX_PTR);
	return (0);
}
