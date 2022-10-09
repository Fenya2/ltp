/*
 * K - num of bots we should use
 * rateSum(N)/N=X
 * => rateSum(N) = XN (1)
 * 
 * (rateSum(N)+k)/(N+K) <= Y
 * => from(1):
 * XN/(N+K) <= Y
 * XN <= YN+YK
 * YK >= XN-YN
 * K >= (XN-YN)/Y
 * =>
 * |-------------------|
 * | K = [(XN-YN)/Y]+1 |
 * |-------------------|
 *
*/

#include <iostream>
using namespace std;
int main() {
	float X = 0;
	float Y = 0;
	int N = 0;
	int K = 0;
	
	cout << "X:";
	cin >> X;
	X = X + 0.5 - 0.00000001;
	cout << "Y:";
	cin >> Y;
	cout << "N:";
	cin >> N;

	K = ((N*(X-Y))/Y)/1 + 1;
	cout << K << endl;
}
