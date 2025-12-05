/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by copilot           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vec.h"

t_vec2	vec2_scale(t_vec2 v, float scalar)
{
	t_vec2	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}
