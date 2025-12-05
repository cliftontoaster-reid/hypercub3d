/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by copilot           #+#    #+#             */
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
