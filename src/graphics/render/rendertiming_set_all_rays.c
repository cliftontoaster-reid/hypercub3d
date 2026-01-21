/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendertiming_set_all_rays.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:55:36 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/19 15:43:13 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/render.h"

void	rendertiming_set_all_rays(t_rendertiming *t, float time)
{
	t->all_rays = time;
}
