/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by copilot           #+#    #+#             */
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
