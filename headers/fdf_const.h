/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:01:46 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 14:03:50 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

# include <utility>

# include <Mlx.hpp>
# include <Map.hpp>

const int	WIN_SIZE_X = 500;
const int	WIN_SIZE_Y = 500;

using Pair = std::pair<Mlx *, Map *>;

#endif