/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_on_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:11:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:19:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_on_press(t_key_state *k, int c, void (*on_press)(void *),
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
			event->on_press = on_press;
			event->param = param;
			return ;
		}
		event = event->next;
	}
	event = malloc(sizeof(t_key_event));
	if (!event)
		return ; // Handle error
	event->keycode = c;
	event->on_press = on_press;
	event->on_release = NULL;
	event->param = param;
	event->next = k->events;
	k->events = event;
}
