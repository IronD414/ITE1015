#include <vector>

class IntegerSet
{
public:
	IntegerSet();
	~IntegerSet();

	int FindNumber(int num);
	void AddNumber(int num);
	void DeleteNumber(int num);

	int GetItem(int pos);
	std::vector<int> GetAll();
private:
	std::vector<int> numbers_;
};