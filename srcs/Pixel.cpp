/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pixel.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:07:00 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 17:16:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Pixel.hpp>
#include <cmath>

Pixel::Pixel(void)
{}
Pixel::~Pixel(void)
{}

int		Pixel::get_x(void) const
{
	return (this->x);
}
int		Pixel::get_y(void) const
{
	return (this->y);
}
void	Pixel::set_x(int x)
{
	this->x = x;
}
void	Pixel::set_y(int y)
{
	this->y = y;
}

Pixel&	Pixel::operator=(const Pixel& obj)
{
	if (this != &obj)
	{
		this->x = obj.get_x();
		this->y = obj.get_y();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Pixel& obj)
{
	out << std::dec << "x="<< obj.x << " y=" << obj.y << std::endl;
	return (out);
}

static unsigned int	interpolate_color(unsigned int color_0, unsigned int color_1, float t);

void	Pixel::print_line(Mlx* obj_Mlx, unsigned int color_0, Pixel obj_Pixel, unsigned int color_1) {
	int x0 = x;
	int y0 = y;
	int x1 = obj_Pixel.get_x();
	int y1 = obj_Pixel.get_y();

	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;

	while (x0 != x1 || y0 != y1) {
		float t = sqrt(static_cast<float>(dx * dx + dy * dy)) / sqrt(static_cast<float>((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
		unsigned int current_color = interpolate_color(color_0, color_1, t);

		obj_Mlx->put_pxl(x0, y0, 0xFFFFFFFF);

		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

static unsigned int	interpolate_color(unsigned int color_0, unsigned int color_1, float t) {
	unsigned char r0 = (color_0 >> 16) & 0xFF;
	unsigned char g0 = (color_0 >> 8) & 0xFF;
	unsigned char b0 = color_0 & 0xFF;

	unsigned char r1 = (color_1 >> 16) & 0xFF;
	unsigned char g1 = (color_1 >> 8) & 0xFF;
	unsigned char b1 = color_1 & 0xFF;

	unsigned char r = static_cast<unsigned char>((1 - t) * r0 + t * r1);
	unsigned char g = static_cast<unsigned char>((1 - t) * g0 + t * g1);
	unsigned char b = static_cast<unsigned char>((1 - t) * b0 + t * b1);

	return (r << 16) | (g << 8) | b;
}
