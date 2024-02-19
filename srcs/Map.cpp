	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:11:39 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:23:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_const.h>

#include <Map.hpp>

#include <string>
#include <fstream>

Map::Map(std::string name)
{
	if (name.size() <= 4 || name.compare(name.size() - 4, 4, ".fdf"))
		throw std::ios_base::failure("Error: Wrong file extension");
	std::fstream	file(name, std::ios::in);

	if (!file.is_open())
		throw std::ios_base::failure("Error: Unable to open the file!");
	try
	{
		file >> *this;
	}
	catch (const std::runtime_error& error)
	{
		throw std::runtime_error(error.what());
	}
}
Map::Map(std::fstream file)
{
	file >> *this;
}
Map::Map(void)
{}
Map::~Map(void)
{}

std::istream&	operator>>(std::istream& in, Map& obj_Map)
{
	obj_Map.color_i = 0;

	try
	{
		in >> obj_Map.vMap;
		obj_Map.set_coord();
	}
	catch (const std::runtime_error& error)
	{
		throw std::runtime_error(error.what());
	}
	return (in);
}
std::ostream&	operator<<(std::ostream& out, Map& obj_Map)
{
	out << obj_Map.vMap;
	return (out);
}

static long double	calc_len(size_t x_len, size_t y_len);

bool	Map::set_coord(void)
{
	size_t	count_i = vMap.size();
	size_t	size_line = vMap[0].size();
	size_t	count_j;
	size_t		j;
	long double len;

	len = calc_len(size_line, count_i);
	for (size_t i = 0; i < count_i; i++)
	{
		count_j = vMap[i].size();
		if (count_j != size_line)
			throw std::runtime_error("Error: Parsing");
		for (j = 0; j < count_j; j++)
		{
			vMap[i][j].set_Point_coord(
				(j - ((long double)(count_j - 1) / 2)) * len,
				(i - ((long double)(count_i - 1) / 2)) * len);
		}
	}
	return (true);
}

static long double	calc_len(size_t x_len, size_t y_len)
{
	long double	len;

	if (WIN_SIZE_X / x_len >= WIN_SIZE_Y / y_len)
		len = (double)(WIN_SIZE_Y - 1) / (x_len + 1);
	else
		len = (double)(WIN_SIZE_X - 1) / (y_len + 1);
	return (len * 0.5);
}