#include "intset.h"
#include <iostream>
#include <vector>

IntegerSet::IntegerSet(){}
IntegerSet::~IntegerSet(){}
std::vector<int> IntegerSet::GetAll()
{
	for (int i = 0; i < this->numbers_.size(); ++i)
	{
		std::cout << this->numbers_[i] << " ";
	}
	std::cout << std::endl;
	return this->numbers_;
}
int IntegerSet::FindNumber(int num)
{
	for (int i = 0; i < this->numbers_.size(); ++i)
	{
		if (this->numbers_[i] == num) return i;
	}
	return -1;
}
void IntegerSet::AddNumber(int num)
{
	if (this->FindNumber(num) == -1) this->numbers_.push_back(num);
	this->GetAll();
}
void IntegerSet::DeleteNumber(int num)
{
	if (this->FindNumber(num) != -1) this->numbers_.erase(this->numbers_.begin()+this->FindNumber(num)); 
	this->GetAll();
}
int IntegerSet::GetItem(int pos)
{
	if (pos >= this->numbers_.size()) return -1;
	else return this->numbers_[pos];
}