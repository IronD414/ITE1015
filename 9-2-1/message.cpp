#include "message.h"
#include <iostream>

MessageBook::MessageBook(){}
MessageBook::~MessageBook(){}
void MessageBook::DeleteMessage(int number)
{
	this->messages_.erase(number);
}
void MessageBook::AddMessage(int number, const std::string& message)
{
	this->DeleteMessage(number);
	this->messages_.insert(make_pair(number, message));
}
std::vector<int> MessageBook::GetNumbers()
{
	std::vector<int> phones;
	for (auto it = this->messages_.begin(); it != this->messages_.end(); ++it)
	{
		phones.push_back(it->first);
	}
	return phones;
}
const std::string& MessageBook::GetMessage(int number)
{
	if (this->messages_.find(number) == this->messages_.end()) return "";
	else return this->messages_[number];
}