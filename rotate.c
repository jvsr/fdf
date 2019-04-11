/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 16:03:22 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 12:15:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fdf.h"
#include "libft/libft.h"

void	rotate_x(t_mlx_data *mlx_data, int i, int x_axis)
{
	int	y;
	int	z;

	y = i / mlx_data->x * mlx_data->zoom;
	z = mlx_data->pixels->origin[i] * mlx_data->zoom;
	mlx_data->pixels->y[i] = y * cos(x_axis * M_PI / 180)\
							+ z * sin(x_axis * M_PI / 180);
	mlx_data->pixels->z[i] = -y * sin(x_axis * M_PI / 180)\
							+ z * cos(x_axis * M_PI / 180);
}

void	rotate_y(t_mlx_data *mlx_data, int i, int y_axis)
{
	int		x;
	int		z;

	x = i % mlx_data->x * mlx_data->zoom;
	z = mlx_data->pixels->z[i];
	mlx_data->pixels->x[i] = x * cos(y_axis * M_PI / 180)\
							+ z * sin(y_axis * M_PI / 180);
	mlx_data->pixels->z[i] = -x * sin(y_axis * M_PI / 180)\
							+ z * cos(y_axis * M_PI / 180);
}

void	rotate_z(t_mlx_data *mlx_data, int i, int z_axis)
{
	int	x;
	int	y;

	x = mlx_data->pixels->x[i];
	y = mlx_data->pixels->y[i];
	mlx_data->pixels->x[i] = x * cos(z_axis * M_PI / 180)\
							- y * sin(z_axis * M_PI / 180);
	mlx_data->pixels->y[i] = x * sin(z_axis * M_PI / 180)\
							+ y * cos(z_axis * M_PI / 180);
}

void	rotate_iso(t_mlx_data *mlx_data, int i)
{
	int previous_x;
	int previous_y;

	previous_x = i % mlx_data->x * mlx_data->zoom;
	previous_y = i / mlx_data->x * mlx_data->zoom;
	mlx_data->pixels->x[i] = (previous_x - previous_y) * cos(0.523599);
	mlx_data->pixels->y[i] = (previous_x + previous_y) * sin(0.523599)\
						- (mlx_data->pixels->origin[i] * mlx_data->zoom);
}

void	rotate_all_axis(t_mlx_data *mlx_data)
{
	int i;

	i = 0;
	while (i < mlx_data->x * mlx_data->y)
	{
		rotate_x(mlx_data, i, mlx_data->axis->x_axis);
		rotate_y(mlx_data, i, mlx_data->axis->y_axis);
		rotate_z(mlx_data, i, mlx_data->axis->z_axis);
		if (mlx_data->iso)
			rotate_iso(mlx_data, i);
		i++;
	}
}
