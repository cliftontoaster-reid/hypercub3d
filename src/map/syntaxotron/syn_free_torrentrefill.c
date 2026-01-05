/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_free_torrentrefill.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:29:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include "utils/torrentrefill.h"
#include <stdlib.h>

bool	syn_free_torrentrefill(t_torrentrefill *refill)
{
	if (!refill)
		return (false);
	if (refill->refilled)
		getthisouttahere((void **)refill->refilled, refill->desk->height);
	if (refill->to_refill)
		free(refill->to_refill);
	free(refill);
	return (true);
}
