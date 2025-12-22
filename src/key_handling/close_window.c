/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:18:22 by mbores            #+#    #+#             */
/*   Updated: 2025/12/22 14:42:02 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

int close_window(t_holy_cow *all)
{
    mlx_destroy_window(all->window->mlx, all->window->mlx_win);
    mlx_destroy_display(all->window->mlx);
    free(all->window);
    free(all->content);
    table_free(all->map);
    free(all);
    exit(0);
}
