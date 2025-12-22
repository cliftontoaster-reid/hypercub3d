/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:36:10 by mbores            #+#    #+#             */
/*   Updated: 2025/12/22 15:06:05 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"

int key_handler(int keycode, t_holy_cow *all)
{
    if (keycode == 65307)
		  close_window(all);
    return (0);
}