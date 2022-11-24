#include "my_container.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	MyContainer<int> container1(n);
	operator>><int>(cin, container1);
	operator<<<int>(cout ,container1) << endl;
	cin >> n;
	MyContainer<float> container2(n);
	operator>><float>(cin, container2);
	operator<<<float>(cout ,container2) << endl;
	cin >> n;
	MyContainer<string> container3(n);
	operator>><string>(cin, container3);
	operator<<<string>(cout ,container3) << endl;
	return 0;
}
