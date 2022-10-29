#include "setfunc.h"
#include <iostream>

size_t GetOperator(const std::string& str)
{
	auto op_pos = str.find_first_of("+");
	if (op_pos == std::string::npos) 
		op_pos = str.find_first_of("*");
	if (op_pos == std::string::npos) 
	{
		auto temp = str.find_first_of("-");
		while (temp != std::string::npos && str.at(temp + 1) != ' ')
			temp = str.find_first_of("-", temp + 1);
		op_pos = temp;
	}
	return op_pos;
}
std::set<int> parseSet(const std::string& str)
{
	std::set<int> set0;
	auto lpos = str.find_first_of("{");
	auto rpos = str.find_first_of("}");
	size_t lblank = lpos;
	size_t rblank = str.find_first_of(" ", lblank);
	while (rblank != rpos-1)
	{
		lblank = rblank;
		rblank = str.find_first_of(" ", lblank+1);
		auto x = std::stoi(str.substr(lblank+1, rblank-lblank-1));
		set0.insert(x);
	}
	return set0;
}
void printSet(const std::set<int>& set0)
{
	if (set0.size() == 0) std::cout << "{ }" << std::endl;
	else
	{
		std::cout << "{";
		for (auto it = set0.begin(); it != set0.end(); ++it)
		{
			std::cout << " " << *it;
		}
		std::cout << " }" << std::endl;
	}
}
std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1)
{
	std::set<int> rset;
	for (auto it0 = set0.begin(); it0 != set0.end(); ++it0)
	{
		for (auto it1 = set1.begin(); it1 != set1.end(); ++it1)	
		{
			if (*it0 == *it1) rset.insert(*it0);
		}
	}
	return rset;
}
std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1)
{
	std::set<int> rset;
	for (auto it0 = set0.begin(); it0 != set0.end(); ++it0)
	{
		rset.insert(*it0);
	}
	for (auto it1 = set1.begin(); it1 != set1.end(); ++it1)
	{
		rset.insert(*it1);
	}
	return rset;
}
std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1)
{
    std::set<int> rset;
	for (auto it0 = set0.begin(); it0 != set0.end(); ++it0)
	{
		rset.insert(*it0);
	}
	for (auto it1 = set1.begin(); it1 != set1.end(); ++it1)
	{
		if (rset.find(*it1) != rset.end()) rset.erase(*it1);
	}
	return rset;
}
