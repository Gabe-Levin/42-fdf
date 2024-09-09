/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/09 01:48:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <main.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

#define MAX_ROWS 19
#define MAX_COLS 11

typedef struct s_pointData
{
	int		x;
	int		y;
	int		z;
	int		dx;
	int		dy;
}			t_pointData;


t_pointData	*parseInput(const char *filename)
{
	t_pointData *matrix;
    char *buffer;
	int fd;
    int byte_cnt;
    
    ft_printf("%s", buffer);
    
}

int main(void)
{
    parseInput("./maps/42.fdf");
    return 0;
}

