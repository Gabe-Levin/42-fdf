/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowFunctions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:19:01 by glevin            #+#    #+#             */
/*   Updated: 2024/09/12 23:31:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWFUNCTIONS_H
# define WINDOWFUNCTIONS_H

# include "main.c"

int		close_window(t_mlxData *img);
int		key_hook(int keycode, t_mlxData *img);
void	initializeWindow(t_mlxData *img);

#endif
