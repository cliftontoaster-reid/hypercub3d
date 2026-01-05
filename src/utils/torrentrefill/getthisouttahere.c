/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getthisouttahere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:24:32 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:32:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/torrentrefill.h"
#include <stdlib.h>

void	getthisouttahere(void **list, size_t height)
{
	size_t	y;

	y = 0;
	while (y < height)
	{
		free(list[y]);
		y++;
	}
	free(list);
}
