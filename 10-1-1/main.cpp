#include "sorted.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	SortedArray SA;

	string input = ".";
	string nums;

	while (input != "quit")
	{
        cin >> input;
		if (input == "add")
		{
			getline(cin, nums);
			getline(cin, nums);
			int blank_pos = 0;
			while (blank_pos != string::npos)
			{
			    if (nums.find_first_of(" ", blank_pos) != string::npos) SA.AddNumber(stoi(nums.substr(blank_pos, nums.find_first_of(" ", blank_pos) - blank_pos)));
			    else 
			    {
			        SA.AddNumber(stoi(nums.substr(blank_pos, nums.length() - blank_pos)));
			        break;
			    }
			    blank_pos = nums.find_first_of(" ", blank_pos) + 1;
			}
		}else if (input =="ascend")
		{
			vector<int> asc = SA.GetSortedAscending();
			for (auto it = asc.begin(); it != asc.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}else if (input == "descend")
		{
			vector<int> des = SA.GetSortedDescending();
			for (auto it = des.begin(); it != des.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}else if (input =="max")
		{
			cout << SA.GetMax() << endl;
		}else if (input =="min")
		{
			cout << SA.GetMin() << endl;
		}else if (input == "quit") break;
	}

	return 0;
}