/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:34:04 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:34:04 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vec.h"

t_vec2	vec2i_normalize(t_vec2i v)
{
	float	mag;
	t_vec2	res;

	mag = vec2i_magnitude(v);
	if (mag == 0.0f)
	{
		res.x = 0.0f;
		res.y = 0.0f;
	}
	else
	{
		res.x = (float)v.x / mag;
		res.y = (float)v.y / mag;
	}
	return (res);
}
