/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_update_button.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:04:08 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:04:24 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"

// Updates the mouse button state
void	mouse_update_button(t_mouse_state *m, unsigned char b, bool p)
{
	if (b < 0 || b > 7)
		return ;
	m->buttons[b] = p;
}
