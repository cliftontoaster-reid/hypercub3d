/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_scanstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:31 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/05 10:48:39 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/syntaxotron.h"
#include <stddef.h>

ssize_t	syn_scanstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!syn_validchar(str[i]))
			return (i);
		i++;
	}
	return (-1);
}
