/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:30:38 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/05 12:03:26 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>
#include <stddef.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}			t_vec2;

t_vec2		vec2_new(float x, float y);
t_vec2		vec2_add(t_vec2 a, t_vec2 b);
t_vec2		vec2_sub(t_vec2 a, t_vec2 b);
t_vec2		vec2_scale(t_vec2 v, float scalar);
float		vec2_dot(t_vec2 a, t_vec2 b);
float		vec2_magnitude(t_vec2 v);
t_vec2		vec2_normalize(t_vec2 v);

typedef struct s_vec2i
{
	int		x;
	int		y;
}			t_vec2i;

t_vec2i		v2i(int x, int y);
t_vec2i		vec2i_new(int x, int y);
t_vec2i		vec2i_add(t_vec2i a, t_vec2i b);
t_vec2i		vec2i_sub(t_vec2i a, t_vec2i b);
t_vec2i		vec2i_scale(t_vec2i v, int scalar);
int			vec2i_dot(t_vec2i a, t_vec2i b);
float		vec2i_magnitude(t_vec2i v);
t_vec2		vec2i_normalize(t_vec2i v);
