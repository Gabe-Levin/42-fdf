/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:17:23 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 12:23:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	is_valid_input(char *s)
{
	if (s[0] == ' ' || s[0] == '\n')
	{
		return (0);
	}
	return (1);
}

int	is_valid_map(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: opening file\n");
		return (0);
	}
	close(fd);
	return (1);
}
