/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_validate_unamerican.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:59 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:28:50 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/syntaxotron.h"
#include <stdlib.h>

bool	syn_validate_unamerican(t_table *desk)
{
	t_torrentrefill	*refill;
	bool			result;

	refill = syn_init_torrentrefill(desk);
	if (!refill)
		return (false);
	result = syn_run_torrentrefill(refill, desk->player_pos);
	syn_free_torrentrefill(refill);
	return (result);
}
