#include <iostream>
#include <string>

using namespace std;
 
int main()
{
  int* arr = new int[5];
  arr[5] = 1;
  cout << arr[5] << endl;
}
