/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 13:30:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/04 12:18:25 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_printline
{
	int			dx;
	int			dy;
	int			p;
	int			p2;
	int			xi;
	int			yi;
	int			x;
	int			y;
}				t_printline;

typedef struct	s_axis
{
	int			x_axis;
	int			y_axis;
	int			z_axis;
}				t_axis;

typedef struct	s_pixels
{
	int			*x;
	int			*y;
	int			*z;
	int			*origin;
}				t_pixels;

typedef struct	s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			win_x;
	int			win_y;
	int			max_z;
	int			min_z;
	int			offset_x;
	int			offset_y;
	int			offset_x_bias;
	int			offset_y_bias;
	int			zoom;
	int			iso;
	int			color;
	t_axis		*axis;
	t_pixels	*pixels;
}				t_mlx_data;

# define WIN_X 2400
# define WIN_Y 1200
# define INIT_X -54
# define INIT_Y 27
# define INIT_Z -18
# define INIT_ZOOM 20

# define MENU_COLOR 0xFFFFFF
# define LINE_COLOR 0x007D7D
# define BUFF_SIZE_FDF 10000

# define ISO mlx_data->iso
# define MLX_PTR mlx_data->mlx_ptr
# define WIN_PTR mlx_data->win_ptr
# define X_AXIS mlx_data->axis->x_axis
# define Y_AXIS mlx_data->axis->y_axis
# define Z_AXIS mlx_data->axis->z_axis

int				main(int ac, char **av);
/*
**		>>>>>>>>	UTIL_FUNCTIONS
*/
int				set_biggest(int i0, int i1);
int				set_smallest(int i0, int i1);
int				determine_x(char *file_string);
int				determine_y(char *file_string);
/*
**		>>>>>>>>	VALIDATE_FUNCTIONS
*/
void			str_is_int(char *num);
void			check_all_lines_equal(char *file_string, t_mlx_data *mlx_data);
int				check_if_in_screen(t_mlx_data *mlx_data, int i0, int i1);
/*
**		>>>>>>>>	UTIL_PRINT_FUNCTIONS
*/
void			print_usage(void);
void			exit_failure_errno(void);
void			draw_menu(t_mlx_data *mlx_data);
void			exit_failure_message(char *message);
/*
**		>>>>>>>>	ROTATE_FUNCTIONS
*/
void			rotate_all_axis(t_mlx_data *mlx_data);
void			rotate_x(t_mlx_data *mlx_data, int i, int x_axis);
void			rotate_y(t_mlx_data *mlx_data, int i, int y_axis);
void			rotate_z(t_mlx_data *mlx_data, int i, int z_axis);
void			set_axis(t_axis *axis, int x_rot, int y_rot, int z_rot);
/*
**		>>>>>>>>	KEY_PRESS_FUNCTIONS
*/
void			set_iso_key_press(t_mlx_data *mlx_data);
void			set_reset_key_press(t_mlx_data *mlx_data);
void			set_zoom_key_press(int keycode, t_mlx_data *mlx_data);
void			set_bias_key_press(int keycode, t_mlx_data *mlx_data);
void			set_axis_key_press(int keycode, t_mlx_data *mlx_data);
void			set_color_key_press(int keycode, t_mlx_data *mlx_data);
/*
**		>>>>>>>>	OFFSET_FUNCTIONS
*/
void			set_init_offset(t_mlx_data *mlx_data);
/*
**		>>>>>>>>	INIT_FUNCTIONS
*/
t_axis			*init_axis(void);
t_mlx_data		*init_mlx_data(char **av);
t_pixels		*read_given_file(t_mlx_data *mlx_data, int fd);

#endif
