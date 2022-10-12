#include <string>
#include <iostream>

using namespace std;

int main ()
{
	string seq;
	getline(cin, seq);
	char cur_br;
	int cur_br_index = 0;
	int max_deep = 0;
	int cur_deep = 0;
	for(int i = 0; i < seq.size(); i++)
	{
		if(seq[i] == '[' || seq[i]== '(')
		{
			cur_br = seq[i];
			cur_br_index = i;
			cur_deep++;
			continue;
		}
		if( (cur_br == '[' && seq[i] == ']') || (cur_br == '(' && seq[i] == ')') )
		{
			max_deep = max(cur_deep, max_deep);
			cur_deep--;
			for(int j = cur_br_index - 1; j >= 0; j--) //Хуйня
			{
				if( seq[j]=='(' || seq[j]=='[' )
				{
					cur_br = seq[j];
					cur_br_index = j;
					break;
				}
			}
			continue;
		}
		if( (cur_br == '[' && seq[i] == ')') || (cur_br == '(' && seq[i] == ']') )
		{
			cout << "incorrect exp." << endl;
			return 0;
		}
		
	}
cout << "correct exp. Max deep: " << max_deep << endl;
return 0;
}

