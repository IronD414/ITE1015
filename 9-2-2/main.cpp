#include "setfunc.h"
#include <iostream>

using namespace std;

int main()
{
	string input = ".";

	while (input != "0")
	{
		getline(cin, input);
		if (GetOperator(input) == string::npos) break;
		auto op_pos = GetOperator(input);
		auto set0 = parseSet(input);
		auto set1 = parseSet(input.substr(op_pos));
		auto op = input[op_pos];

		if (op == '*')
		{
			printSet(getIntersection(set0, set1));
		} else if (op == '+')
		{
			printSet(getUnion(set0, set1));
		} else if (op == '-')
		{
			printSet(getDifference(set0, set1));
		} else if (op == '.') break;
	}

	return 0;
}