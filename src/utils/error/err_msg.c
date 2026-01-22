/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:04:12 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 11:09:28 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

void	err_msg(const char *header, const char *msg)
{
	if (header)
		printf(ERR_COL_RED "Error\n%s: " ERR_COL_RESET, header);
	else
		printf(ERR_COL_RED "Error\n" ERR_COL_RESET);
	if (msg)
		printf("%s\n", msg);
	else
		printf("An unknown error occurred.\n");
}
