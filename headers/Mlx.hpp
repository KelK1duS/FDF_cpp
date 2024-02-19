/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:00:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 14:07:38 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HPP
# define MLX_HPP

class Mlx
{
private:
	void	*ptr;
	void	*win;
	void	*img;

public:
	Mlx(char *title);
	~Mlx(void);

	void	*get_ptr(void);
	void	*get_win(void);
	void	*get_img(void);

	void	loop(void);
	void	put_pxl(int x, int y, int color);
	void	clear(void);
	void	update(void);
};

#endif