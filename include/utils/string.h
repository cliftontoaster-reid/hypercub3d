/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:25:29 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/05 11:23:40 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct s_string
{
	char	*data;
	size_t	length;
	size_t	capacity;
}			t_string;

t_string	*string_new(void);
t_string	*string_from(const char *src);
t_string	*string_from_file(const char *filepath);

size_t		string_reserve(t_string *string, size_t new_capacity);
size_t		string_push(t_string *string, const char *src);
void		string_free(t_string *string);

size_t		line_len(const char *s);
bool		line_is_empty(const char *s, size_t len);
