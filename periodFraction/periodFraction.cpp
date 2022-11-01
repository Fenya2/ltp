#define max_length 10
#include <iostream>

using namespace std;

int check_period(int start, int end)
{
	if (end - start == 3)
		return 2;
	else
		return 1;
}

int main()
{
	int a;
	int b;
	
	cout << "a: "; cin >> a;
	if (a > 100 || a < 1)
	{
		cout << "Input error." << endl;
		return 0;
	}
	
	cout << "b: "; cin >> b;
	if (b > 100 || b <= a)
	{
		cout << "Input error." << endl;
		return 0;
	}
	
	int remainders[max_length];
	int answer[max_length];
	for (int i = 0; i < size(remainders); i++)
	{
		remainders[i] = -1;
		answer[i] = -1;
	}
	
	int cur_remainder = (a*10)%b;
	answer[0] = (a*10)/b;
	remainders[0] = cur_remainder;
	bool match = false;
	int counter = 1;
	int period_idx;
	while(!match && counter < max_length)
	{
		answer[counter] = (remainders[counter-1]*10) / b;
		remainders[counter] = (remainders[counter-1]*10) % b;
		for(int i = 0; i < counter-1; i++)
		{
			if(remainders[i] == remainders[counter] && answer[i] == answer[counter])
			{
				period_idx = i;
				match = true;
			}
		}
		counter++;
	}
	
	for (int i = 0; i < size(remainders); i++)
	{
		cout << remainders[i];
	}
	cout << endl;
	for (int i = 0; i < size(remainders); i++)
	{
		cout << answer[i];
	}
	cout << endl;
	
	cout << counter - period_idx << endl;
		
	cout << a << "/" << b << " = " << "0.";
	for(int i = 0; i < counter - check_period(period_idx, counter); i++ )
	{
		if(i == period_idx)
			cout << "(";
		cout << answer[i];
	}
	cout << ")" << endl;
	return 0;
}
