/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:18:22 by mbores            #+#    #+#             */
/*   Updated: 2026/01/14 13:09:16 by lfiorell         ###   ########.fr       */
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
