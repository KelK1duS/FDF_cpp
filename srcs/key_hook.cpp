/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:50:24 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 14:12:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include <fdf.h>
#include <fdf_keymap.h>

int	key_hook_Pair(int keycode, void *obj)
{
	Pair	*obj_Pair = static_cast<Pair*>(obj);

	//std::cout << "keycode" << keycode << std::endl;
	if (keycode == KEY_ESCAPE)
	{
		delete obj_Pair->first;
		delete obj_Pair->second;
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_X)
	{
		std::string	title;
		Map	*obj_Map;

		std::cout << "new Map: ";
		std::cin >> title;
		try
		{
			obj_Map = new Map(title);
		}
		catch(const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
		std::cout << "Map change: " << title << std::endl;
		delete obj_Pair->second;
		obj_Pair->second = obj_Map;
	}
	return (0);
}
