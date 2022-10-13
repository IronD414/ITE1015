#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	string user_input = ".";
	while (user_input != "quit")
	{
		getline(cin, user_input);
		if(user_input == "quit")
		{
		    break;
		}
		int len = user_input.length();
		string str = user_input;
		for (int i = 0; i < len; ++i)
		{
			if (isalpha(user_input[i]))
			{
				str[i] = isupper(user_input[i]) ? tolower(user_input[i]) : toupper(user_input[i]);
			}
		}
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}
	return 0;
}