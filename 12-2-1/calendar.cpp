#include "calendar.h"
#include <string>

MyCalendar::MyCalendar(): _year(0), _month(1), _day(1){}
MyCalendar::MyCalendar(int year, int month, int day): _year(year), _month(month), _day(day){}
bool MyCalendar::NextDay(int n)
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int newyear = this->_year;
	int newmonth = this->_month;
	int newday = MyCalendar::ComputeDaysFromYearStart(newyear, newmonth, this->_day) + n;
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
	return this->SetDate(newyear, newmonth, newday);
}
bool MyCalendar::SetDate(int year, int month, int day)
{
	if (0<=year && year<=9999 & 1<=month && month<=12 && 1<= day)
	{	// 1st filter
		if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{	// month that has 31 days
			if (day>31) return false; 
		}else if (month==2)
		{	// consider leap years
			if (this->GetDaysInYear(year)==365)
			{	// not leap year
				if (day>28) return false;
			}else if (day>29) return false;	// leap year
		}else if (day>30) return false;	// month that has 30 days
		this->_year = year;
		this->_month = month;
		this->_day = day;
		return true;
	}else return false;
}
int MyCalendar::year() const{return this->_year;}
int MyCalendar::month() const{return this->_month;}
int MyCalendar::day() const{return this->_day;}
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

std::ostream& operator<<(std::ostream& out, const MyCalendar& c)
{
	out << c.year() << "." << c.month() << "." << c.day();
	return out;
}
std::istream& operator>>(std::istream& in, MyCalendar& c)
{
	std::string input;
	in >> input;
	int pos1 = input.find_first_of(".");
	int y = stoi(input.substr(0, pos1));
	int pos2 = input.find_first_of(".", pos1+1);
	int m = stoi(input.substr(pos1+1, pos2-pos1-1));
	int d = stoi(input.substr(pos2+1, input.length()-pos2-1));
	if (!c.SetDate(y, m, d)) std::cout << "Invalid date: " << y << "." << m << "." << d << std::endl;
	return in;
}