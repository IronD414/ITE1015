class Account
{
public:
	int id = -1;
	int balance = 0;
};

class AccountManager
{
public:
	int num_accounts = 0;
	Account accounts[10];

	void deposit(int id, int amount);
	void withdraw(int id, int amount);
	void transfer(int from, int to, int amount);
	void check(int id);
};