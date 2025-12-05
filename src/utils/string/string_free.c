/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:41:15 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 13:42:13 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/string.h"
#include <stdlib.h>

/// You won't believe this, it reads into the void.
/// Crazy right?
void	string_free(t_string *s)
{
	if (s == NULL)
		return ;
	free(s->data);
	free(s);
}
