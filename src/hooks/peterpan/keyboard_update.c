/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:39:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 17:21:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "stdio.h"

// Updates the keyboard state
void	keyboard_update(t_key_state *k, int c, bool p)
{
	t_key_event	*event;

	if (c < 0 || c >= KEYS_COUNT)
		return ;
	k->keys[c] = p;
	event = &k->events[c];
	if (p && event->on_press)
		event->on_press(event->param);
	else if (!p && event->on_release)
		event->on_release(event->param);
}
