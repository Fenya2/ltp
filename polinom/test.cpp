#include <iostream>
#include <string>

using namespace std;
 
int main()
{
  string str = "abcdef";
  string slice = str.substr(2, 1);
  cout << slice << endl;
}
