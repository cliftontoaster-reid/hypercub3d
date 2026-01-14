/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_is_button_pressed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:59:40 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 15:59:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"

// Checks if a mouse button is pressed
bool	mouse_is_button_pressed(t_mouse_state *m, unsigned char b)
{
	if (b >= 8)
		return (false);
	return (m->buttons[b]);
}
