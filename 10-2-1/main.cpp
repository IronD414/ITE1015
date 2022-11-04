#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool getMatch(string s)
{
	stack<int> prts;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			prts.push(1);	
		}else if (s[i] == ')')
		{
			if (prts.empty())
			{
				return false;
			}else
			{
				prts.pop();
			}
		}
	}
	return prts.empty();
}

int main()
{
	char input = ' ';
	string expression;

	while (1)
	{
		cin >> input;

		if (input == 'e')
		{
		    getline(cin, expression, ' ');
			getline(cin, expression);
			auto result = getMatch(expression) ? "matched" : "not matched";
			cout << result << endl;
		}else if (input == 'q') break;
	}

	return 0;
}