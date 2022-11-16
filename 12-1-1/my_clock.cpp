#include "my_clock.h"
#include <string>

void MyClock::Tick(int seconds)
{
	int cur = this->_hour * 3600 + this->_min * 60 + this->_sec;
	cur += seconds;
	if (cur < 0)
	{
	    while (cur < 0)
	    {
	        cur += 86400;
	    }
	}else if (cur >= 86400)
	{
	    while (cur >= 86400)
	    {
	        cur -= 86400;
	    }
	}
	this->_hour = cur / 3600;
	cur %= 3600;
	this->_min = cur / 60;
	cur %= 60;
	this->_sec = cur;
	std::cout << *this << std::endl;
}
bool MyClock::SetTime(int hour, int minute, int second)
{
	if (0<=hour && hour<24 && 0<=minute && minute<60 && 0<=second && second<60)
	{
		this->_hour = hour;
		this->_min = minute;
		this->_sec = second;
		return true;
	}
	else return false;
}
// If input is invalid, it returns false and does not change the time
int MyClock::hour() const {return this->_hour;}
int MyClock::minute() const {return this->_min;}
int MyClock::second() const {return this->_sec;}
// You can add any function if needed

// The format for input/output is hh:mm:ss
std::ostream& operator<<(std::ostream& out, const MyClock& c)
{
	out << c.hour() << ":" << c.minute() << ":" << c.second();
	return out;
}
std::istream& operator>>(std::istream& in, MyClock& c)
{
	std::string input;
	in >> input;
	int pos1 = input.find_first_of(":");
	int h = stoi(input.substr(0, pos1));
	int pos2 = input.find_first_of(":", pos1+1);
	int m = stoi(input.substr(pos1+1, pos2-pos1-1));
	int s = stoi(input.substr(pos2+1, input.length()-pos2-1));
	if (!c.SetTime(h, m, s)) std::cout << "Invalid time: " << h << ":" << m << ":" << s << std::endl;
	else std::cout << c << std::endl;
	return in;
}