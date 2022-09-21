#include <iostream>
#include "accounts.h"
using namespace std;

int main()
{
	int flag = 1;
	char req; // user's repeated input
	AccountManager manager;

	while(flag)
	{
		int amount; int id1; int id2;

		cout << "Job?" << endl;
		cin >> req;

		switch(req)
		{
			case 'N':
				if (manager.num_accounts == 10)
				{
					cout << "Failure!" << endl;
				}
				else
				{
					cout << "Success!" << endl;
					manager.accounts[manager.num_accounts].id = manager.num_accounts;
					manager.check(manager.num_accounts++);
				}
				break;
			case 'D':
				cin >> id1 >> amount;
				manager.deposit(id1, amount);
				manager.check(id1);
				break;
			case 'W':
				cin >> id1 >> amount;
				manager.withdraw(id1, amount);
				manager.check(id1);
				break;
			case 'T':
				cin >> id1 >> id2 >> amount;
				manager.transfer(id1, id2, amount);
				int precede; int follow;
				if (id1 < id2)
				{
					precede = id1; follow = id2;
				}
				else
				{
					precede = id2; follow = id1;
				}
				manager.check(precede);
				manager.check(follow);
				break;
			case 'Q':
				flag = 0;
				break;
		}
	}
	return 0;
}