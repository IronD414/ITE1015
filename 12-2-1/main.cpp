#include "calendar.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	MyCalendar calendar;
	string input; string next;
	int t;
	while (1)
	{
	    cin >> input;
		if (input == "quit") break;
		else if (input == "set")
		{
			cin >> calendar;
			cout << calendar << endl;
		}else if (input == "next")
		{
			cin >> next;
			if (next == "day")
			{
			    if (!calendar.NextDay()) cout << "Invalid date" << endl;
			}else if (!calendar.NextDay(stoi(next))) cout << "Invalid date" << endl;
			cout << calendar << endl;
		}
	}
	return 0;
}