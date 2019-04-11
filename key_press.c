/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:02:00 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 13:34:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_iso_key_press(t_mlx_data *mlx_data)
{
	if (ISO)
		ISO = 0;
	else
		ISO = 1;
	rotate_all_axis(mlx_data);
}

void	set_zoom_key_press(int keycode, t_mlx_data *mlx_data)
{
	if ((keycode == 27 || keycode == 78) && mlx_data->zoom > 1)
		mlx_data->zoom--;
	else if (keycode == 24 || keycode == 69)
		mlx_data->zoom++;
	rotate_all_axis(mlx_data);
}

void	set_bias_key_press(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == 123)
		mlx_data->offset_x_bias -= 20;
	else if (keycode == 124)
		mlx_data->offset_x_bias += 20;
	else if (keycode == 125)
		mlx_data->offset_y_bias += 20;
	else if (keycode == 126)
		mlx_data->offset_y_bias -= 20;
}

void	set_axis_key_press(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == 84)
		set_axis(mlx_data->axis, X_AXIS + 9, Y_AXIS, Z_AXIS);
	else if (keycode == 91)
		set_axis(mlx_data->axis, X_AXIS - 9, Y_AXIS, Z_AXIS);
	else if (keycode == 88)
		set_axis(mlx_data->axis, X_AXIS, Y_AXIS + 9, Z_AXIS);
	else if (keycode == 86)
		set_axis(mlx_data->axis, X_AXIS, Y_AXIS - 9, Z_AXIS);
	if (keycode == 13)
		set_axis(mlx_data->axis, X_AXIS, Y_AXIS, Z_AXIS + 9);
	if (keycode == 12)
		set_axis(mlx_data->axis, X_AXIS, Y_AXIS, Z_AXIS - 9);
	rotate_all_axis(mlx_data);
}

void	set_reset_key_press(t_mlx_data *mlx_data)
{
	set_axis(mlx_data->axis, 0, 0, 0);
	mlx_data->offset_x_bias = 0;
	mlx_data->offset_y_bias = 0;
	rotate_all_axis(mlx_data);
}
