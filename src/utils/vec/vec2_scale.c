/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:33:36 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:33:37 by lfiorell         ###   ########.fr       */
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
