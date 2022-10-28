#include "message.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = ".";
	int num; string message;
	MessageBook book;

	while (input != "quit")
	{
		cin >> input;

		if (input == "add")
		{
			cin >> num;
			getline(cin, message, ' ');
			getline(cin, message);
			book.AddMessage(num, message);
		}else if (input == "delete")
		{
			cin >> num;
			book.DeleteMessage(num);
		}else if (input == "print")
		{
			cin >> num;
			cout << book.GetMessage(num) << endl;
		}else if (input == "list")
		{
			auto phones = book.GetNumbers();
			for (auto it = phones.begin(); it != phones.end(); ++it)
			{
				cout << *it << ": " << book.GetMessage(*it) << endl;
			}
		}
		else if (input == "quit") break;
	}

	return 0;
}