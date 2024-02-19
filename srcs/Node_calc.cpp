/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_calc.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 17:17:25 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Node.hpp>
#include <fdf_const.h>

void	Node::calc(void)
{
	obj_Pixel.set_x(obj_Point.get_x() + (WIN_SIZE_X / 2));
	obj_Pixel.set_y(obj_Point.get_y() + (WIN_SIZE_Y / 2));
}

void	Node::put_pxl(Mlx* obj_Mlx, size_t i)
{
	obj_Mlx->put_pxl(obj_Pixel.get_x(), obj_Pixel.get_y(), colors[i]);
}

void	Node::print_line(Mlx* obj_Mlx, size_t i, Node obj_Node)
{
	std::cerr << "ICI" << std::endl;
	obj_Pixel.print_line(obj_Mlx, colors[i], obj_Node.get_Pixel(), obj_Node.get_color(i));
}
