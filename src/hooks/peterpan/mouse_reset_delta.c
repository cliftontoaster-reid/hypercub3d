/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_reset_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:01:33 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 16:04:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "utils/vec.h"

// Resets the mouse movement delta
void	mouse_reset_delta(t_mouse_state *m)
{
	m->delta = vec2_new(0.0f, 0.0f);
}
