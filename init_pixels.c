/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:02:13 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 12:23:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "fdf.h"
#include "libft/libft.h"

void		init_pixels_data(t_pixels *pixels, char *file_string)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (file_string[i])
	{
		while (ft_isspace(file_string[i]))
			i++;
		if (ft_isdigit(file_string[i])\
			|| file_string[i] == '-' || file_string[i] == '+')
		{
			str_is_int(&file_string[i]);
			pixels->origin[x] = ft_atoi(&file_string[i]);
			if ((file_string[i] == '-' || file_string[i] == '+')\
				&& !ft_isdigit(file_string[i + 1]))
				exit_failure_message("Error: Invalid number given");
			i++;
			x++;
		}
		while (ft_isdigit(file_string[i]))
			i++;
		if (!ft_isspace(file_string[i]) && file_string[i])
			exit_failure_message("Error: Invalid number given");
	}
}

t_pixels	*init_pixels(char *file_string, t_mlx_data *mlx_data)
{
	t_pixels	*pixels;

	mlx_data->x = determine_x(file_string);
	mlx_data->y = determine_y(file_string);
	check_all_lines_equal(file_string, mlx_data);
	pixels = (t_pixels*)malloc(sizeof(t_pixels));
	if (!pixels)
		exit_failure_errno();
	pixels->x = (int*)malloc(mlx_data->x * mlx_data->y * sizeof(int));
	pixels->y = (int*)malloc(mlx_data->x * mlx_data->y * sizeof(int));
	pixels->z = (int*)malloc(mlx_data->x * mlx_data->y * sizeof(int));
	pixels->origin = (int*)malloc(mlx_data->x * mlx_data->y * sizeof(int));
	if (!pixels->x || !pixels->y || !pixels->z || !pixels->origin)
		exit_failure_errno();
	init_pixels_data(pixels, file_string);
	free(file_string);
	return (pixels);
}

char		*create_file_string(int fd)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE_FDF + 1];
	char	*file_string;

	file_string = NULL;
	ret = read(fd, buf, BUFF_SIZE_FDF);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (file_string)
		{
			tmp = file_string;
			file_string = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
			file_string = ft_strdup(buf);
		ret = read(fd, buf, BUFF_SIZE_FDF);
	}
	if (ret == -1)
		exit_failure_message("Error: reading failed");
	return (file_string);
}

t_pixels	*read_given_file(t_mlx_data *mlx_data, int fd)
{
	char	*file_string;

	file_string = NULL;
	if (fd == -1)
		exit_failure_errno();
	if (fd > 0)
		file_string = create_file_string(fd);
	return (init_pixels(file_string, mlx_data));
}
