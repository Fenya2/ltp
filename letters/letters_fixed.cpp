#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input_file;
	ofstream letter_file;
	string pattern = "";
	

	input_file.open("pattern.txt");
	if(!input_file.is_open())
    {
		cout << "can't 'open file pattern.txt." << endl;
		return 0;
	}
	
	while(!input_file.eof())
	{
		pattern += input_file.get();
	}
	input_file.close();
	
	input_file.open("names.txt");
	if (!input_file.is_open())
	{
		cout << "file 'names.txt' did not open*." << endl;
		return 0;
	}
	string name;
	while (getline(input_file, name))
	{
		letter_file.open("letter_to_" + name + ".txt");
		for(int i = 0; i < pattern.size(); i++)
		{
			if(pattern[i] == '*')
			{
				letter_file << name;
				continue;
			}
			letter_file << pattern[i];
		}
		letter_file.close();
	}
}
