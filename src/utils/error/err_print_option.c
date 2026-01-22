/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:10:00 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/22 12:10:00 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

void	err_print_option_error(const char *line, const char *msg)
{
	printf(ERR_COL_RED "Error\n" ERR_COL_RESET);
	printf("Option parsing: %s\n", msg);
	printf("Line: " ERR_COL_YELLOW "%s" ERR_COL_RESET "\n", line);
}
