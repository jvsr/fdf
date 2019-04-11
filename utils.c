/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 18:35:35 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/03 17:55:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	set_axis(t_axis *axis, int x_rot, int y_rot, int z_rot)
{
	axis->x_axis = x_rot;
	axis->y_axis = y_rot;
	axis->z_axis = z_rot;
}

int		set_biggest(int i0, int i1)
{
	if (i0 > i1)
		return (i0);
	else
		return (i1);
}

int		set_smallest(int i0, int i1)
{
	if (i0 < i1)
		return (i0);
	else
		return (i1);
}

int		determine_x(char *file_string)
{
	int i;
	int	x;

	i = 0;
	x = 0;
	while (file_string[i] && file_string[i] != '\n')
	{
		while (ft_isspace(file_string[i]) && file_string[i] != '\n')
			i++;
		if (ft_isdigit(file_string[i])\
			|| file_string[i] == '-' || file_string[i] == '+')
		{
			x++;
			if (file_string[i] == '-' || file_string[i] == '+')
				i++;
		}
		while (ft_isdigit(file_string[i]))
			i++;
		if (!ft_isspace(file_string[i]) && file_string[i])
			exit_failure_message("Error: Invalid number given");
	}
	return (x);
}

int		determine_y(char *file_string)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	while (file_string[i])
	{
		if (file_string[i] == '\n')
			y++;
		i++;
	}
	if (file_string[i - 1] != '\n')
		exit_failure_message("Error: file must end with a new line");
	return (y);
}
