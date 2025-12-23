/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_on_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:12:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 17:24:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_on_release(t_key_state *k, int c, void (*on_release)(void *),
		void *param)
{
	if (c < 0 || c >= KEYS_COUNT)
		return ;
	k->events[c].on_release = on_release;
	k->events[c].param = param;
}
