/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_on_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:11:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 17:24:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include <stdlib.h>

void	keyboard_on_press(t_key_state *k, int c, void (*on_press)(void *),
		void *param)
{
	if (c < 0 || c >= KEYS_COUNT)
		return ;
	k->events[c].on_press = on_press;
	k->events[c].param = param;
}
