#include "my_string.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    MyString A;
	MyString B; 
	string input;
	while (1)
	{
		char op; char rs; int n;
		cin >> input;
		if (input == "new")
		{
			cout << "enter a" << endl;
			cin >> A;
			cout << "enter b" << endl;
			cin >> B;
		}else if (input == "quit") break;
		else
		{
			cin >> op;
			if (op == '+')
			{
				cin >> rs;
				MyString newString;
				auto lo = (input == "a") ? A : B;
				auto ro = (rs == 'a') ? A : B;
				newString = lo + ro;
				cout << newString << endl;
			}else if (op == '*')
			{
				cin >> n;
				MyString newString;
				auto lo = (input == "a") ? A : B;
				newString = lo * n;
				cout << newString << endl;
			}
		}
	}
	return 0;
}