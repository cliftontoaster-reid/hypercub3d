/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:40:42 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/14 13:10:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/string.h"
#include <fcntl.h>
#include <unistd.h>

/// This right there, is peak C programming.
static int	open_file(const char *filepath)
{
	return (open(filepath, O_RDONLY));
}

static int	read_file(int fd, t_string *ret)
{
	const size_t	buf_size = 1024;
	char			buffer[1024 + 1];
	ssize_t			bytes_read;

	bytes_read = read(fd, buffer, buf_size);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (string_push(ret, buffer) == 0)
			return (0);
		bytes_read = read(fd, buffer, buf_size);
	}
	if (bytes_read < 0)
		return (-1);
	return (1);
}

t_string	*string_from_file(const char *filepath)
{
	int			fd;
	t_string	*ret;
	int			res;

	fd = open_file(filepath);
	if (fd < 0)
		return (NULL);
	ret = string_new();
	if (ret == NULL)
	{
		close(fd);
		return (NULL);
	}
	res = read_file(fd, ret);
	close(fd);
	if (res != 1)
	{
		string_free(ret);
		return (NULL);
	}
	return (ret);
}
