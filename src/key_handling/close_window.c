/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:18:22 by mbores            #+#    #+#             */
/*   Updated: 2026/01/09 14:52:03 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/minimap.h"


void	close_window(void *stuff)
{
	t_renderctx	*ctx;

	ctx = stuff;
	render_free(ctx);
	exit(0);
}
