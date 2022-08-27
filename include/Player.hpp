/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:50:04 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/27 13:50:38 by tnoulens         ###   ########.fr       */
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
		uint32_t	dude;
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
	mvwaddch(curwin, yloc, xloc, ' ');
	yloc--;
	if (yloc < 1)
		yloc = 1;
}

void	player::mvdown()
{
	mvwaddch(curwin, yloc, xloc, ' ');
	yloc++;
	if (yloc > ymax - 2)
		yloc = ymax - 2;
}

void	player::mvleft()
{
	mvwaddch(curwin, yloc, xloc, ' ');
	xloc--;
	if (xloc < 1)
		xloc = 1;
}

void	player::mvright()
{
	mvwaddch(curwin, yloc, xloc, ' ');
	xloc++;
	if (xloc > xmax - 2)
		xloc = xmax - 2;
}

int	player::getmv()
{
	int	choice;

	choice = wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
	return (choice);
}

void	player::display()
{
	mvwaddch(curwin, yloc, xloc, dude);
}

#endif
