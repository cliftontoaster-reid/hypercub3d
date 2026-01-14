/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:08:46 by lfiorell          #+#    #+#             */
/*   Updated: 2026/01/14 13:26:01 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/mlx.h"

static void	free_windows(t_my_xvar *mlx)
{
	t_my_win_list	*w;
	t_my_win_list	*next;

	w = mlx->win_list;
	while (w)
	{
		next = w->next;
		if (mlx->display && w->window)
			XDestroyWindow(mlx->display, w->window);
		if (mlx->display && w->gc)
			XFreeGC(mlx->display, w->gc);
		free(w);
		w = next;
	}
}

static void	free_display(t_my_xvar *mlx)
{
	if (mlx->display && mlx->private_cmap)
		XFreeColormap(mlx->display, mlx->cmap);
	if (mlx->display)
	{
		if (mlx->do_flush)
			XFlush(mlx->display);
		XCloseDisplay(mlx->display);
	}
}

void	mlx_free(void *ptr)
{
	t_my_xvar	*mlx;

	if (!ptr)
		return ;
	mlx = (t_my_xvar *)ptr;
	if (mlx->win_list)
		free_windows(mlx);
	free_display(mlx);
	free(mlx);
}
