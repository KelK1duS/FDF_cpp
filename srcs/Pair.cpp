/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:58:11 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:56:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include <fdf.h>

bool	init_Pair(Mlx	**obj_Mlx, Map	**obj_Map, char *title)
{
	try
	{
		*obj_Map = new Map(title);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	try
	{
		*obj_Mlx = new Mlx(title);
	}
	catch(const std::runtime_error& e)
	{
		delete *obj_Map;
		std::cerr << e.what() << std::endl;
		return (false);
	}
	return (true);
}
