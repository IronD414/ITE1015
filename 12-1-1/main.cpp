#include "my_clock.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	MyClock clock;
	string input;
	int t;
	while (1)
	{
	    cin >> input;
		if (input == "quit") break;
		else if (input == "set")
		{
			cin >> clock;
		}else if (input == "tick")
		{
			cin >> t;
			clock.Tick(t);
		}
	}
	return 0;
}