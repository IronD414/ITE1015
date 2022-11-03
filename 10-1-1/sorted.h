#include <vector>
#include <algorithm>

class SortedArray
{
public:
	SortedArray();
	~SortedArray();
	void AddNumber(int num);
	std::vector<int> GetSortedAscending();
	std::vector<int> GetSortedDescending();
	int GetMax();
	int GetMin();
private:
	std::vector<int> numbers_;
};

bool Compare(int i, int j);