	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:58:09 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/07 14:34:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Node.hpp>
#include <string>

static unsigned int	skip_atoi(std::string str);

Node::Node(void)
{}
Node::~Node(void)
{}

Point	Node::get_Point(void) const
{
	return (this->obj_Point);
}
void	Node::set_Point(Point obj_Point)
{
	this->obj_Point = obj_Point;
}
Pixel	Node::get_Pixel(void) const
{
	return (this->obj_Pixel);
}
void	Node::set_Pixel(Pixel obj_Pixel)
{
	this->obj_Pixel = obj_Pixel;
}
std::vector<unsigned int>	Node::get_colors(void) const
{
	return (this->colors);
}
void	Node::set_colors(std::vector<unsigned int> colors)
{
	this->colors = colors;
}
void	Node::add_color(unsigned int color)
{
	this->colors.push_back(color);
}
unsigned int	Node::get_color(size_t i)
{
	return (this->colors[i]);
}

Node&	Node::operator=(const Node& obj)
{
	if (this != &obj)
	{
		this->obj_Point = obj.get_Point();
		this->obj_Pixel = obj.get_Pixel();
		this->colors = obj.get_colors();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Node& obj)
{
	out << obj.obj_Point << obj.colors;
	return (out);
}

std::ostream&	operator<<(std::ostream& out, const std::vector<unsigned int>&	colors)
{
	out << "colors :";
	size_t	i = 0;

	while (i < colors.size())
	{
		out << " " << std::hex << colors[i];
		i++;
	}
	out << std::endl;
	return (out);
}

std::istream& operator>>(std::istream& in, Node& Node)
{
	std::string	str;

	if (in >> str)
	{
		Node.obj_Point = Node.get_Point();
		Node.obj_Point.set_z(std::stoi(str));
		Node.add_color(0xFFFFFFFF);
		Node.add_color(skip_atoi(str));
	}
	return (in);
}

void	Node::set_Point_coord(long double x, long double y)
{
	obj_Point.set_x(x);
	obj_Point.set_y(y);
}

static unsigned int	skip_atoi(std::string str)
{
	size_t	pos;

	pos = str.find(",0x");
	if (pos != std::string::npos)
		return (stoul(str, &pos, 16) + 0xFF000000);
	return (0xFF808080);
}
