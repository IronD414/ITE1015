#include "calendar.h"

InvalidDate::InvalidDate(int year, int month, int day): year(year), month(month), day(day) {}
// private: year, month, day
// friend <<

MyCalendar::MyCalendar(){this->SetDate(0, 1, 1);}
MyCalendar::MyCalendar(int year, int month, int day){SetDate(year, month, day);}
bool MyCalendar::NextDay(int n)
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int newyear = this->year;
	int newmonth = this->month;
	int newday = MyCalendar::ComputeDaysFromYearStart(newyear, newmonth, this->day) + n;
	if (newday < 0)
	{	// year goes backward
		while (newday < 0) newday += MyCalendar::GetDaysInYear(--newyear);
	}else if (newday > MyCalendar::GetDaysInYear(newyear))
	{	// year goes forward
		while (newday > MyCalendar::GetDaysInYear(newyear)) newday -= MyCalendar::GetDaysInYear(newyear++);
	}
	if (MyCalendar::GetDaysInYear(newyear)!=365) days[1] = 29;
	int i = 0;
	while (days[i] < newday)
	{
		newday -= days[i++];
	}
	newmonth = i + 1;
	try {this->SetDate(newyear, newmonth, newday);}
	catch (InvalidDate& x)
	{
		return false;
	}
	return true;
}
void MyCalendar::SetDate(int year, int month, int day)
{
	int daysof[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (this->GetDaysInYear(year)==366) daysof[2] = 29;
	if (year<0 || year>9999 || month<1 || month>12 || day<1 || day>daysof[month])
	{
		throw InvalidDate(year, month, day);
	}else this->year=year; this->month=month; this->day=day;
}
int MyCalendar::_year() const{return this->year;}
int MyCalendar::_month() const{return this->month;}
int MyCalendar::_day() const{return this->day;}
int MyCalendar::GetDaysInYear(int year)
{
	if (year%400!=0 && (year%100==0 || year%4!=0)) return 365; 
	else return 366;
}
int MyCalendar::ComputeDaysFromYearStart(int year, int month, int day)
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (MyCalendar::GetDaysInYear(year)!=365) days[1] = 29;
	int result = 0;
	for (int i = 0; i < month-1; ++i) result += days[i];
	result += day;
	return result;
}
// private year, month, day

std::ostream& operator<<(std::ostream& out, const MyCalendar& c)
{
	out << c._year() << "." << c._month() << "." << c._day();
	return out;
}
std::istream& operator>>(std::istream& in, MyCalendar& c)
{
	int y, m, d; char x;
	in >> y >> x >> m >> x >> d;
	c.SetDate(y, m, d);
	return in;
}
std::ostream& operator<<(std::ostream& out, const InvalidDate& msg)
{
	out << "Invalid date: " << msg.year << "." << msg.month << "." << msg.day;
	return out;
}
// format: yyyy.mm.dd