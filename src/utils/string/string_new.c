/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:44:04 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 11:47:34 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/string.h"

t_string	*string_new(void)
{
	t_string	*ret;

	ret = malloc(sizeof(t_string));
	ft_bzero(ret, sizeof(t_string));
	return (ret);
}
