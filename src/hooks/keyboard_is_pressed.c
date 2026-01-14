/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_is_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:38:20 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:19:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"

// Checks if a key is pressed
bool	keyboard_is_pressed(t_key_state *k, int c)
{
	if (c < 0 || c >= KEYS_COUNT)
		return (false);
	return (k->keys[c]);
}
