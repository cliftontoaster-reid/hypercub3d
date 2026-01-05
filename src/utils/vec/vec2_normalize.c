/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:33:30 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:33:31 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vec.h"

t_vec2	vec2_normalize(t_vec2 v)
{
	float	magnitude;
	t_vec2	result;

	magnitude = vec2_magnitude(v);
	if (magnitude == 0.0f)
	{
		result.x = 0.0f;
		result.y = 0.0f;
	}
	else
	{
		result.x = v.x / magnitude;
		result.y = v.y / magnitude;
	}
	return (result);
}
