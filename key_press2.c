/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:42:00 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/03 18:42:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_key_press(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == 18)
		mlx_data->color = 0x0000FF;
	else if (keycode == 19)
		mlx_data->color = 0x00FF00;
	else if (keycode == 20)
		mlx_data->color = 0xFF0000;
	else if (keycode == 21)
		mlx_data->color = 0xFFFF00;
	else if (keycode == 23)
		mlx_data->color = 0xFF00FF;
	else if (keycode == 22)
		mlx_data->color = 0x00FFFF;
	else if (keycode == 26)
		mlx_data->color = 0xFFFFFF;
	else if (keycode == 28)
		mlx_data->color = 0x000000;
}
