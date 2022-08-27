/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:50:04 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/27 17:55:49 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PLAYER__H__
# define __PLAYER__H__

# include "Entity.hpp"
# include <ncurses.h>
# include <string>
# include <ctime>

class Player : public Entity
{

public:
	Player();
	Player(double x, double y, const wchar_t[3]);


};

#endif
