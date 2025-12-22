/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:20:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:10:06 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_free(t_key_state *k)
{
	t_key_event	*event;
	t_key_event	*next;

	if (!k)
		return ;
	event = k->events;
	while (event)
	{
		next = event->next;
		free(event);
		event = next;
	}
	free(k);
}
