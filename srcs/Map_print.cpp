/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_print.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:55:28 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:58:55 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Map.hpp>

Mlx&	operator<<(Mlx& obj_Mlx, Map *obj_Map)
{
	obj_Map->display_mlx(&obj_Mlx);
	return (obj_Mlx);
}

void	Map::display_mlx(Mlx *obj_Mlx)
{	
	for (size_t i = 0; i < vMap.size(); i++)
	{
		for (size_t j = 0; j < vMap[i].size(); j++)
		{
			vMap[i][j].put_pxl(obj_Mlx, color_i);
			if (i > 0)
				vMap[i][j].print_line(obj_Mlx, i, vMap[i - 1][j]);
			if (j > 0)
				vMap[i][j].print_line(obj_Mlx, i, vMap[i][j - 1]);
		}
	}
}
