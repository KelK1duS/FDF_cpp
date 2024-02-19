/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:42:17 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/07 14:33:48 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <ostream>

class Point
{
private:
	long double	x;
	long double	y;
	long double	z;

public:
	Point(void);
	~Point(void);

	long double	get_x(void) const;
	long double	get_y(void) const;
	long double	get_z(void) const;
	void	set_x(long double x);
	void	set_y(long double y);
	void	set_z(long double z);

	Point&	operator=(const Point& obj);

	friend std::ostream&	operator<<(std::ostream& out, const Point& obj);
};


#endif