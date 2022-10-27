#include "intset.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	IntegerSet is;
	string input = "."; int n;
	while (input != "quit")
	{
		cin >> input;
		if (input == "add")
		{
			cin >> n;
			is.AddNumber(n);
		} else if (input == "del")
		{
			cin >> n;
			is.DeleteNumber(n);
		} else if (input == "get")
		{
			cin >> n;
			cout << is.GetItem(n) << endl;
		} else if (input == "quit")
		{
			break;
		}
	}

	return 0;
}