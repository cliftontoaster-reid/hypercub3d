/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_on_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:12:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:19:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_on_release(t_key_state *k, int c, void (*on_release)(void *),
		void *param)
{
	t_key_event	*event;

	if (c < 0 || c >= KEYS_COUNT)
		return ;
	event = k->events;
	while (event)
	{
		if (event->keycode == c)
		{
			event->on_release = on_release;
			event->param = param;
			return ;
		}
		event = event->next;
	}
	event = malloc(sizeof(t_key_event));
	if (!event)
		return ; // Handle error
	event->keycode = c;
	event->on_press = NULL;
	event->on_release = on_release;
	event->param = param;
	event->next = k->events;
	k->events = event;
}
