/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pixel.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:41:14 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 17:06:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_HPP
# define PIXEL_HPP

#include <ostream>
#include <Mlx.hpp>

class Pixel
{
private:
	int	x;
	int	y;

public:
	Pixel(void);
	~Pixel(void);

	int	get_x(void) const;
	int	get_y(void) const;
	void	set_x(int x);
	void	set_y(int y);

	Pixel&	operator=(const Pixel& obj);

	friend std::ostream&	operator<<(std::ostream& out, const Pixel& obj);

	void	print_line(Mlx* obj_Mlx, unsigned int color_0, Pixel obj_Pixel, unsigned int color_1);
};

#endif