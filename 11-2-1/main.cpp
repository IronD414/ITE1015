#include "my_vector.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int n; MyVector lo; char op; string rin; MyVector ro; int c; MyVector result;
	MyVector A; MyVector B;
	while (1)
	{
	    cin >> input;
		if (input == "new")
		{
			cin >> n;
			cout << "enter a" << endl;
			MyVector a(n);
			cin >> a;
			A = a;
			cout << "enter b" << endl;
			MyVector b(n);
			cin >> b;
			B = b;
		}else if (input == "quit") break;
		else
		{
			lo = input[0]=='a' ? A : B;
			cin >> op >> rin;
			if (rin != "a" && rin != "b")
			{
				c = stoi(rin);
				if (op == '+')
				{
					result = lo + c;
					cout << result << endl;
				}else if (op == '-')
				{
					result = lo - c;
					cout << result << endl;
				}
			}
			else
			{
				ro = rin == "a" ? A : B;
				if (op == '+')
				{
					result = lo + ro;
					cout << result << endl;
				}else if (op == '-')
				{
					result = lo - ro;
					cout << result << endl;
				}
			}
		}
	}
	return 0;
}