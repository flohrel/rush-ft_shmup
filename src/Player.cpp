/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:30:32 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/27 17:56:02 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player()
: Entity()
{ }

Player::Player(double x, double y, const wchar_t ws[3])
: Entity(x, y, L"⯇⯈")
{ }
