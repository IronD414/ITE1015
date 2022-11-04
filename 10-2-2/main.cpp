#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void pushMap(map<string, int>& m, string s)
{
	if (m.find(s) == m.end()) m.insert(make_pair(s, 1));
	else m[s]++;
	return;
}

int main()
{
	fstream fs;
	map<string, int> freq;
	string line;

	char input;
	string file_name;

	while (1)
	{
		cin >> input;
		if (input == 'f')
		{
			getline(cin, file_name, ' ');
			getline(cin, file_name);
			fs.open(file_name);
			while (!fs.eof())
			{
				getline(fs, line);
				int blank_pos = 0;
				while (line.find_first_of(" ", blank_pos) != string::npos)
				{
					pushMap(freq, line.substr(blank_pos, line.find_first_of(" ", blank_pos)-blank_pos));	
					blank_pos = line.find_first_of(" ", blank_pos) + 1;
				}
				pushMap(freq, line.substr(blank_pos, line.length()-blank_pos));
			}
			fs.close();

			auto max = freq.begin();

			for (auto i = freq.begin(); i != freq.end(); ++i)
			{
				if (i->second > max->second) max = i;
			}

			for (auto it = freq.begin(); it != freq.end(); ++it)
			{
				if (it->second == max->second) cout << it->first << " " << it->second << endl;
			}

		}else if (input == 'q') break;
	}
	
	return 0;
}