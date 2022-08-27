/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:50:04 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/27 13:02:37 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PLAYER__H__
# define __PLAYER__H__

# include <iostream>
# include <ncurses.h>

class player
{
	public:
		player(WINDOW *win, int y, int x, char c);
	void	mvup();
	void	mvdown();
	void	mvleft();
	void	mvright();
	int		getmv();
	void	display();

	private:
		int		xloc;
		int		yloc;
		int		xmax;
		int		ymax;
		char	dude;
		WINDOW	*curwin;
};

player::player(WINDOW *win, int y, int x, char c)
{
	curwin = win;
	yloc = y;
	xloc = x;
	getmaxyx(curwin, ymax, xmax);
	keypad(curwin, true);
	dude = c;
}

void	player::mvup()
{
	yloc--;
	if (yloc < 1)
		yloc = 1;
}

void	player::mvdown()
{
	yloc++;
	if (yloc > ymax - 2)
		yloc = ymax - 2;
}

void	player::mvleft()

#endif
