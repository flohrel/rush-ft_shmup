#ifndef __TIME__H__
# define __TIME__H__

# include <time.h>

class Time
{

public:
	Time();
	void		get_fps();

	double		cur_time;
	double		old_time;
	double		frame_time;
	double		move_speed;

};

#endif