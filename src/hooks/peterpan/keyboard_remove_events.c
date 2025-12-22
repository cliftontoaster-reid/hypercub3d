/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_remove_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:13:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:19:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_remove_events(t_key_state *k, int c)
{
	t_key_event	*event;
	t_key_event	*prev;

	if (c < 0 || c >= KEYS_COUNT)
		return ;
	event = k->events;
	prev = NULL;
	while (event)
	{
		if (event->keycode == c)
		{
			if (prev)
				prev->next = event->next;
			else
				k->events = event->next;
			free(event);
			return ;
		}
		prev = event;
		event = event->next;
	}
}
