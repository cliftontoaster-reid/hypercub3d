/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:18:22 by mbores            #+#    #+#             */
/*   Updated: 2026/01/08 13:37:30 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

void	close_window(void *stuff)
{
	t_renderctx	*all;

	all = stuff;
	mlx_destroy_window(all->mlx, all->win_game);
	mlx_destroy_window(all->mlx, all->win_minimap);
	mlx_destroy_display(all->mlx);
	table_free(all->map);
	keyboard_free(all->keyboard);
	free(all->mouse);
	free(all);
	exit(0);
}
