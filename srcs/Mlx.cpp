/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:00:22 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/12 14:11:38 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdexcept>

#include <Mlx.hpp>

#include <mlx.h>
#include <fdf_const.h>

Mlx::Mlx(char *title)
{
	ptr = NULL;
	win = NULL;
	img = NULL;
	if (!(ptr = mlx_init()))
		throw std::runtime_error("Error: Failed to initialize Mlx");
	else if (!(win = mlx_new_window(ptr, WIN_SIZE_X, WIN_SIZE_Y, title)))
	{
		if (ptr)
		{
			mlx_destroy_display(ptr);
			ptr = NULL;
		}
		throw std::runtime_error("Error: Failed to create window");
	}
	else if (!(img = mlx_new_image(ptr, WIN_SIZE_X, WIN_SIZE_Y)))
	{
		if (ptr && win)
		{
			mlx_destroy_window(ptr, win);
			win = NULL;
		}
		if (ptr)
		{
			mlx_destroy_display(ptr);
			ptr = NULL;
		}
		throw std::runtime_error("Error: Failed to create Mlx_image");
	}
}

Mlx::~Mlx(void)
{
	if (ptr && img)
	{
		mlx_destroy_image(ptr, img);
		img = NULL;
	}
	if (ptr && win)
	{
		mlx_destroy_window(ptr, win);
		win = NULL;
	}
	if (ptr)
	{
		mlx_destroy_display(ptr);
		ptr = NULL;
	}
}

void	*Mlx::get_ptr(void)
{
	return (ptr);
}

void	*Mlx::get_win(void)
{
	return (win);
}

void	*Mlx::get_img(void)
{
	return (img);
}

void	Mlx::loop(void)
{
	mlx_loop(ptr);
}

void	Mlx::put_pxl(int x, int y, int color)
{
	if (x >= 0 && x < WIN_SIZE_X
		&& y >= 0 && y < WIN_SIZE_Y)
		mlx_set_image_pixel(ptr, img, x, y, color);
}

void	Mlx::clear(void)
{
	for (int i = 0; i < WIN_SIZE_Y; i++)
	{
		for (int j = 0; j < WIN_SIZE_Y; j++)
			mlx_set_image_pixel(ptr, img, j, i, 0xFF000000);
	}
}

void	Mlx::update(void)
{
	mlx_put_image_to_window(ptr, win, img, 0, 0);
}
