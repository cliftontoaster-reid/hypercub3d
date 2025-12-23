/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:39:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 16:34:59 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "stdio.h"

// Updates the keyboard state
void	keyboard_update(t_key_state *k, int c, bool p)
{
	t_key_event	*event;

	printf("Key: %d/%d\n", c, p);
	if (c < 0 || c >= KEYS_COUNT)
		return ;
	k->keys[c] = p;
	event = k->events;
	while (event)
	{
		if (event->keycode == c)
		{
			if (p && event->on_press)
				event->on_press(event->param);
			else if (!p && event->on_release)
				event->on_release(event->param);
		}
		event = event->next;
	}
}
