/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:39:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 16:32:46 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <Node.hpp>
# include <Mlx.hpp>

# include <vector>
# include <cstddef>
# include <istream>

class Map
{
private:
	std::vector<std::vector<Node>>	vMap;

	size_t	color_i;

public:
	Map(std::string name);
	Map(std::fstream file);
	Map(void);
	~Map(void);

	friend std::istream&	operator>>(std::istream& in, Map& obj_Map);
	friend std::ostream&	operator<<(std::ostream& out, Map& obj_Map);

	bool	set_coord(void);
	void	calc(void);
	void	calc(int x, int y);
	void	display_mlx(Mlx *obj_Mlx);
};

std::istream&	operator>>(std::istream& in, std::vector<Node>& Line);
std::istream&	operator>>(std::istream& in, std::vector<std::vector<Node>>& vMap);
std::ostream&	operator<<(std::ostream& out, const std::vector<Node>& Line);
std::ostream&	operator<<(std::ostream& out, const std::vector<std::vector<Node>>& vMap);

Mlx&	operator<<(Mlx& obj_Mlx, Map *obj_Map);

#endif
