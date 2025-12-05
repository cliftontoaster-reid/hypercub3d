/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_row_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:04:26 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/04 15:04:58 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"

size_t	get_longest_row_length(const char *str)
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	while (*str)
	{
		len = 0;
		while (str[len] && str[len] != '\n')
			len++;
		if (len > max_len)
			max_len = len;
		str += len;
		if (*str == '\n')
			str++;
	}
	return (max_len);
}
