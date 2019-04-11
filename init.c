/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 13:35:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/03 18:24:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "fdf.h"
#include "minilibx_macos/mlx.h"

t_axis		*init_axis(void)
{
	t_axis		*axis;

	axis = (t_axis*)malloc(sizeof(t_axis));
	if (!axis)
		exit_failure_errno();
	set_axis(axis, INIT_X, INIT_Y, INIT_Z);
	return (axis);
}

t_mlx_data	*init_mlx_data(char **av)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data*)malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		exit_failure_errno();
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->win_x = WIN_X;
	mlx_data->win_y = WIN_Y;
	mlx_data->win_ptr = mlx_new_window(MLX_PTR, mlx_data->win_x,\
										mlx_data->win_y, "FdF");
	if (!(WIN_PTR))
		exit_failure_errno();
	mlx_data->zoom = INIT_ZOOM;
	mlx_data->iso = 0;
	mlx_data->axis = init_axis();
	mlx_data->pixels = read_given_file(mlx_data, open(av[1], O_RDONLY));
	mlx_data->offset_x_bias = 0;
	mlx_data->offset_y_bias = 0;
	mlx_data->color = LINE_COLOR;
	return (mlx_data);
}
