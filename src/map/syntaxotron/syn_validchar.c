/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_validchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:48:16 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/05 10:49:10 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/syntaxotron.h"

inline bool	syn_validchar(char c)
{
	size_t	i;

	i = 0;
	while (SYN_ALLOWED[i])
	{
		if (c == SYN_ALLOWED[i])
			return (true);
		i++;
	}
	return (false);
}
