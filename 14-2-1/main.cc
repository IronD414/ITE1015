#include "calendar.h"
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
			try {cin >> calendar;}
			catch (InvalidDate& x)
			{
				cout << x << endl;
			}
		}else if (input == "next")
		{
			cin >> next;
			try
			{
				if (next == "day")
				{
					if (!calendar.NextDay()) cout << "Invalid date" << endl;
				}else
				{
					if (!calendar.NextDay(stoi(next))) cout << "Invalid date" << endl;
				} 
			}
			catch (InvalidDate& x)
			{
				cout << x << endl;
			}
		}
		cout << calendar << endl;
	}
	return 0;
}