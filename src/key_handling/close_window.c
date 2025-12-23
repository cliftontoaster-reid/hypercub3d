/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:18:22 by mbores            #+#    #+#             */
/*   Updated: 2025/12/23 16:27:03 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

void	close_window(void *stuff)
{
	t_holy_cow	*all;

	all = stuff;
	mlx_destroy_window(all->window->mlx, all->window->mlx_win);
	mlx_destroy_display(all->window->mlx);
	free(all->window);
	table_free(all->map);
	keyboard_free(all->keyboard);
	free(all->mouse);
	free(all);
	exit(0);
}
