#include "sorted.h"

SortedArray::SortedArray(){}
SortedArray::~SortedArray(){}
void SortedArray::AddNumber(int num)
{
    return this->numbers_.push_back(num);
}
std::vector<int> SortedArray::GetSortedAscending() 
{
    std::sort(this->numbers_.begin(), this->numbers_.end());
    return this->numbers_;
}
std::vector<int> SortedArray::GetSortedDescending() 
{
    std::sort(this->numbers_.begin(), this->numbers_.end(), Compare);
    return this->numbers_;
}
int SortedArray::GetMax() 
{
    return *std::max_element(this->numbers_.begin(), this->numbers_.end());
}
int SortedArray::GetMin()
{
    return *std::min_element(this->numbers_.begin(), this->numbers_.end());
}

bool Compare(int i, int j) 
{
    return i > j;
}