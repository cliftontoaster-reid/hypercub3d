/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:33:46 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:33:47 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vec.h"

t_vec2i	vec2i_add(t_vec2i a, t_vec2i b)
{
	t_vec2i	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}
