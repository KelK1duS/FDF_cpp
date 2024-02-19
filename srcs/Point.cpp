/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:02:52 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/07 17:53:20 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

Point::Point(void)
{}
Point::~Point(void)
{}

long double	Point::get_x(void) const
{
	return (this->x);
}
long double	Point::get_y(void) const
{
	return (this->y);
}
long double	Point::get_z(void) const
{
	return (this->z);
}

void	Point::set_x(long double x)
{
	this->x = x;
}
void	Point::set_y(long double y)
{
	this->y = y;
}
void	Point::set_z(long double z)
{
	this->z = z;
}

Point&	Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->x = obj.get_x();
		this->y = obj.get_y();
		this->z = obj.get_z();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Point& obj)
{
	out << std::dec << "x="<< obj.x << " y=" << obj.y << " z=" << obj.z << std::endl;
	return (out);
}
