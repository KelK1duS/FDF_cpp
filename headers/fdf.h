/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:14:22 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fdf_const.h>

int		key_hook_Pair(int keycode, void *obj);
int		key_hook_pMap(int keycode, void *obj);

bool	init_Pair(Mlx	**obj_Mlx, Map	**obj_Map, char *title);

#endif