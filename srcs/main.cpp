/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:52:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 17:27:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <mlx.h>
#include <fdf.h>

int main(int argc, char **argv) {
	Mlx	*obj_Mlx;
	Map	*obj_Map;

	if (argc != 2) {
		std::cerr << "Error: Wrong arguments number" << std::endl;
		return (1);
	}
	if (!init_Pair(&obj_Mlx, &obj_Map, argv[1]))
		return (1);
	Pair obj_Pair(obj_Mlx, obj_Map);
	obj_Map->calc();
	obj_Map->display_mlx(obj_Mlx);
	obj_Mlx->update();
	mlx_on_event(obj_Mlx->get_ptr(), obj_Mlx->get_win(),
		MLX_KEYDOWN, &key_hook_Pair, &obj_Pair);
	obj_Mlx->loop();
	return (0);
}