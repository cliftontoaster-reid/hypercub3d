/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:25:29 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/03 14:28:16 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

typedef struct s_string
{
	char	*data;
	size_t	length;
	size_t	capacity;
}			t_string;

t_string	*string_new(void);
t_string	*string_from(const char *);
t_string	*string_from_file(const char *filepath);

size_t		string_reserve(t_string *string, size_t new_capacity);
size_t		string_push(t_string *string, const char *src);
void		string_free(t_string *string);