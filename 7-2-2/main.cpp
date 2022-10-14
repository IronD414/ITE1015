#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str; string new_str;
	int before = 0; int after = 0;
	getline(cin, str);
	while (1)
	{
		after = str.find(',', before);
		new_str += str.substr(before, after - before);
		new_str += "\n";
		if (str.find(',', before) == str.npos)
		{
		    break;
		}
		before = after + 1;
	}
	cout << new_str;
	return 0;
}