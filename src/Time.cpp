# include "Time.hpp"

Time::Time()
: cur_time(0), old_time(0), frame_time(0), move_speed(0)
{ }

void	Time::get_fps()
{
	old_time = cur_time;
	cur_time = clock();
	frame_time = (cur_time - old_time) / CLOCKS_PER_SEC;
	move_speed = frame_time * 10.0;
}