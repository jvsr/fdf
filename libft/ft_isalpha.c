/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 19:23:04 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/09 19:23:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'z' && (c <= 'Z' || c >= 'a'))
		return (1);
	return (0);
}
