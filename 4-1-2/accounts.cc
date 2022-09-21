#include <iostream>
#include "accounts.h"
using namespace std;

void AccountManager::deposit(int id, int amount)
{
	if (this->accounts[id].id < 0 || this->accounts[id].balance + amount > 1000000)
	{
		cout << "Failure!" << endl;
	}
	else
	{
		cout << "Success!" << endl;
		this->accounts[id].balance += amount;
	}
}

void AccountManager::withdraw(int id, int amount)
{
	if (this->accounts[id].id < 0 || this->accounts[id].balance - amount < 0)
	{
		cout << "Failure!" << endl;
	}
	else
	{
		cout << "Success!" << endl;
		this->accounts[id].balance -= amount;
	}
}

void AccountManager::transfer(int from, int to, int amount)
{
	if (this->accounts[from].id < 0 || this->accounts[to].id < 0 || this->accounts[from].balance - amount < 0 || this->accounts[to].balance + amount > 1000000)
	{
		cout << "Failure!" << endl;
	}	
	else
	{
		cout << "Success!" << endl;
		this->accounts[from].balance -= amount;
		this->accounts[to].balance += amount;
	}
}

void AccountManager::check(int id)
{
	if (this->accounts[id].id < 0)
	{
		return;
	}
	else
	{
		cout << "Balance of user " << id << ": " << this->accounts[id].balance << endl;
	}
}