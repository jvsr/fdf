/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 18:08:43 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/03 18:04:08 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static int	special_str_is_int_check(int i, char *num)
{
	if (num[i + 0] < '2')
		return (0);
	if (num[i + 1] < '1')
		return (0);
	if (num[i + 2] < '4')
		return (0);
	if (num[i + 3] < '7')
		return (0);
	if (num[i + 4] < '4')
		return (0);
	if (num[i + 5] < '8')
		return (0);
	if (num[i + 6] < '3')
		return (0);
	if (num[i + 7] < '6')
		return (0);
	if (num[i + 8] < '4')
		return (0);
	if (num[0] == '-' && num[i + 9] <= '8')
		return (0);
	else if (num[i + 9] <= '7')
		return (0);
	return (1);
}

void		str_is_int(char *num)
{
	int	i;
	int	count;

	count = 0;
	if (num[0] == '-' || num[0] == '+')
		i = 1;
	else
		i = 0;
	while (isdigit(num[i + count]))
		count++;
	if (count < 10)
		return ;
	if (count > 10)
		exit_failure_message("Error: Parameter does not fit in int");
	if (count == 10 && special_str_is_int_check(i, num))
		exit_failure_message("Error: Parameter does not fit in int");
}

void		check_all_lines_equal(char *file_string, t_mlx_data *mlx_data)
{
	int	i;
	int	x;

	i = 0;
	while (file_string[i])
	{
		x = determine_x(&file_string[i]);
		if (mlx_data->x != x)
			exit_failure_message("Error: Rows are not of equal length");
		while (file_string[i] && file_string[i] != '\n')
			i++;
		if (file_string[i] == '\n')
			i++;
	}
}

int			check_if_in_screen(t_mlx_data *mlx_data, int i0, int i1)
{
	int	x;
	int	y;

	x = set_biggest(mlx_data->pixels->x[i0] + mlx_data->offset_x\
					, mlx_data->pixels->x[i1] + mlx_data->offset_x);
	y = set_biggest(mlx_data->pixels->y[i0] + mlx_data->offset_y\
					, mlx_data->pixels->y[i1] + mlx_data->offset_y);
	if (x < 0 || y < 0)
		return (0);
	x = set_smallest(mlx_data->pixels->x[i0] + mlx_data->offset_x\
					, mlx_data->pixels->x[i1] + mlx_data->offset_x);
	y = set_smallest(mlx_data->pixels->y[i0] + mlx_data->offset_y\
					, mlx_data->pixels->y[i1] + mlx_data->offset_y);
	if (x > WIN_X || y > WIN_Y)
		return (0);
	return (1);
}
