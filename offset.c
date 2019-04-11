/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   offset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:15:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/03 17:53:31 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	set_offset_x(t_mlx_data *mlx_data)
{
	int i;
	int	low_x;
	int	extreme_x;

	i = 0;
	low_x = mlx_data->pixels->x[0];
	extreme_x = mlx_data->pixels->x[0];
	while (i < mlx_data->x * mlx_data->y)
	{
		if (mlx_data->pixels->x[i] > extreme_x)
			extreme_x = mlx_data->pixels->x[i];
		if (mlx_data->pixels->x[i] < low_x)
			low_x = mlx_data->pixels->x[i];
		i++;
	}
	mlx_data->offset_x = (mlx_data->win_x - \
		(ft_abs(extreme_x) - ft_abs(low_x))) / 2 + mlx_data->offset_x_bias;
}

static void	set_offset_y(t_mlx_data *mlx_data)
{
	int i;
	int	extreme_y;
	int	low_y;

	i = 0;
	low_y = mlx_data->pixels->y[0];
	extreme_y = mlx_data->pixels->y[0];
	while (i < mlx_data->x * mlx_data->y)
	{
		if (mlx_data->pixels->y[i] > extreme_y)
			extreme_y = mlx_data->pixels->y[i];
		if (mlx_data->pixels->y[i] < low_y)
			low_y = mlx_data->pixels->y[i];
		i++;
	}
	mlx_data->offset_y = (mlx_data->win_y - \
		(ft_abs(extreme_y) - ft_abs(low_y))) / 2 + mlx_data->offset_y_bias;
}

void		set_init_offset(t_mlx_data *mlx_data)
{
	set_offset_x(mlx_data);
	set_offset_y(mlx_data);
}
