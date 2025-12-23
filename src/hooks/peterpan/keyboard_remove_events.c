/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_remove_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:13:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 17:21:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_remove_events(t_key_state *k, int c)
{
	if (c < 0 || c >= KEYS_COUNT)
		return ;
	k->events[c].on_press = NULL;
	k->events[c].on_release = NULL;
	k->events[c].param = NULL;
}
