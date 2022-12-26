#ifndef __CALENDAR_H__
#define __CALENDAR_H__
#include <iostream>
class InvalidDate 
{
public:
	InvalidDate(int year, int month, int day);
	friend std::ostream& operator<<(std::ostream& out, const InvalidDate& msg);
private:
	int year, month, day;
};
class MyCalendar 
{
public:
	MyCalendar();
	MyCalendar(int year, int month, int day);
	bool NextDay(int n = 1);
	void SetDate(int year, int month, int day);
	int _year() const;
	int _month() const;
	int _day() const;
private:
	static int GetDaysInYear(int year);
	static int ComputeDaysFromYearStart(int year, int month, int day);
 	// compute the days from the date given to the current day.
	int year, month, day;
};
// the format is yyyy.mm.dd
std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);
std::ostream& operator<<(std::ostream& out, const InvalidDate& msg);
#endif // __CALENDAR_H__