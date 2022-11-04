#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	char input = ' ';
	string expression;
	bool result = true;

	stack<int> prts;

	while (1)
	{
		cin >> input;

		if (input == 'e')
		{
		    getline(cin, expression, ' ');
			getline(cin, expression);
			
			for (int i = 0; i < expression.length(); ++i)
			{
				if (expression[i] == '(') prts.push(1);	
				else if (expression[i] == ')')
				{
					if (prts.empty()) result = false;
					else prts.pop();
				}
			}
			if (result) result = prts.empty();

			if (result) cout << "matched" << endl;
			else cout << "not matched" << endl;

			while (!prts.empty()) prts.pop();
		}else if (input == 'q') break;
	}

	return 0;
}