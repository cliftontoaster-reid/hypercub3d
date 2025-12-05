/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:38:54 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 12:39:13 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/string.h"

t_string	*string_from(const char *src)
{
	t_string	*ret;

	ret = string_new();
	if (ret == NULL)
		return (NULL);
	if (string_push(ret, src) == 0)
	{
		string_free(ret);
		return (NULL);
	}
	return (ret);
}
