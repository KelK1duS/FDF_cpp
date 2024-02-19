/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:40:35 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 17:05:52 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <Mlx.hpp>
# include <Point.hpp>
# include <Pixel.hpp>

# include <iostream>
# include <vector>
# include <string>


class Node
{
private:
	Point	obj_Point;
	Pixel	obj_Pixel;

	std::vector<unsigned int>	colors;

public:
	Node(void);
	~Node(void);

	Point	get_Point(void) const;
	void	set_Point(Point obj_Point);
	Pixel	get_Pixel(void) const;
	void	set_Pixel(Pixel obj_Pixel);
	std::vector<unsigned int> get_colors(void) const;
	void	set_colors(std::vector<unsigned int> colors);
	void			add_color(unsigned int color);
	unsigned int	get_color(size_t i);

	Node&	operator=(const Node& obj);

	friend	std::ostream&	operator<<(std::ostream& out, const Node& obj);
	friend	std::istream&	operator>>(std::istream& in, Node& Node);

	void	set_Point_coord(long double x, long double y);
	void	calc(void);
	void	put_pxl(Mlx *obj_Mlx, size_t i);
	void	print_line(Mlx* obj_Mlx, size_t i, Node obj_Node);
};

std::ostream&	operator<<(std::ostream& out, const std::vector<unsigned int>& colors);

#endif