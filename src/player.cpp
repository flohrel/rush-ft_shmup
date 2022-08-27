/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:30:32 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/27 13:53:13 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../include/Player.hpp"

int	main()
{
	initscr();
	noecho();
	cbreak();
	
	int ymax, xmax;
	getmaxyx(stdscr, ymax, xmax);
	WINDOW	*curwin = newwin(20, 50, (ymax / 2) - 10, 10);
	box(curwin, 0, 0);
	refresh();
	wrefresh(curwin);
	player *p = new player(curwin, 1, 1, 'O');
	do
	{
		p->display();
		wrefresh(curwin);
	} while (p->getmv() != 'q');
	endwin();
	return (0);
}
