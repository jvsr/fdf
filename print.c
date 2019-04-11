/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 13:35:43 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 11:15:12 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	exit_failure_errno(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	exit_failure_message(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	ft_printf("Usage: ./fdf:\n	./fdf [map]\n");
	exit(EXIT_FAILURE);
}

void	draw_menu(t_mlx_data *mlx_data)
{
	int y;

	y = 0;
	mlx_string_put(MLX_PTR, WIN_PTR, 65, y += 20, MENU_COLOR, "How to Use");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 35, MENU_COLOR, "Quit: Esc");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR, "Zoom: +/-");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR, "Move: Arrows");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR,\
					"Colors: Key row 1-8");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR, "Rotate:");
	mlx_string_put(MLX_PTR, WIN_PTR, 57, y += 25, MENU_COLOR,\
					"X-Axis - Num pad: 2/8");
	mlx_string_put(MLX_PTR, WIN_PTR, 57, y += 25, MENU_COLOR,\
					"Y-Axis - Num pad: 4/6");
	mlx_string_put(MLX_PTR, WIN_PTR, 57, y += 30, MENU_COLOR, "Z-Axis - Q/E");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR, "ISO: I");
	mlx_string_put(MLX_PTR, WIN_PTR, 15, y += 30, MENU_COLOR, "RESET: R");
	if (ISO)
		mlx_string_put(MLX_PTR, WIN_PTR, 15,\
						mlx_data->win_y - 30, 0x00FF00, "ISO = TRUE");
	else
		mlx_string_put(MLX_PTR, WIN_PTR, 15,\
						mlx_data->win_y - 30, 0xFF0000, "ISO = FALSE");
}
