/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:34:09 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:34:10 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vec.h"

t_vec2i	vec2i_scale(t_vec2i v, int scalar)
{
	t_vec2i	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}
