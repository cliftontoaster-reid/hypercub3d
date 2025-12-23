/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:39:05 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/23 16:35:14 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks/peterpan.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static int	keyboard_yes(int keycode, t_key_state *k)
{
	ft_printf("yes\n");
	if (keycode < 0 || keycode > KEYS_COUNT)
		return (0);
	keyboard_update(k, (unsigned char)keycode, true);
	return (0);
}

static int	keyboard_no(int keycode, t_key_state *k)
{
	ft_printf("no\n");
	if (keycode < 0 || keycode > KEYS_COUNT)
		return (0);
	keyboard_update(k, (unsigned char)keycode, false);
	return (0);
}

// Initializes the keyboard state
t_key_state	*keyboard_init(void *mlx, void *win)
{
	t_key_state	*k;

	(void)mlx;
	k = malloc(sizeof(t_key_state));
	if (!k)
		return (NULL);
	ft_memset(k->keys, false, sizeof(k->keys));
	mlx_hook(win, EVENT_KEY_PRESS, MASK_KEY_PRESS, keyboard_yes, k);
	mlx_hook(win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, keyboard_no, k);
	return (k);
}
