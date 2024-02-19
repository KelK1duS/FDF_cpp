/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_calc.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:30:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:37:18 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Map.hpp>

void	Map::calc(void)
{
	for (size_t i = 0; i < vMap.size(); i++)
	{
		for (size_t j = 0; j < vMap[i].size(); j++)
			vMap[i][j].calc();
	}
}
