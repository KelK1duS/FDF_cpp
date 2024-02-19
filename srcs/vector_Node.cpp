/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_Node.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:52:11 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 13:20:45 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Map.hpp>
#include <sstream>

std::istream&	operator>>(std::istream& in, std::vector<Node>& Line)
{
	while (in.good())
	{
		Node	obj_Node;
		in >> obj_Node;
		Line.push_back(obj_Node);
	}
	return (in);
}

std::istream&	operator>>(std::istream& in, std::vector<std::vector<Node>>& vMap)
{
	std::string	str;

	while (std::getline(in, str))
	{
		std::vector<Node>	Line;
		std::stringstream	istream(str);
		istream >> Line;
		if (Line.size() == 0)
			break;
		vMap.push_back(Line);
	}
	if (vMap.size() == 0)
		throw std::runtime_error("Error: Empty file");
	return (in);
}

std::ostream&	operator<<(std::ostream& out, const std::vector<Node>& Line)
{
	size_t	count = Line.size();

	for (size_t i = 0; i < count; i++)
		out << Line[i];
	return (out);
}
std::ostream&	operator<<(std::ostream& out, const std::vector<std::vector<Node>>& vMap)
{
	size_t	count = vMap.size();

	for (size_t i = 0; i < count; i++)
		out << vMap[i] << std::endl;
	return (out);
}