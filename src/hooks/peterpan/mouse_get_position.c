/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_get_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:59:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/22 15:59:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"

// Gets the current mouse position
t_vec2	mouse_get_position(t_mouse_state *m)
{
	return (m->pos);
}
