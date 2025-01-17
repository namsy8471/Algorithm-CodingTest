#include <iostream>
#include <cmath>

using namespace std;

//MenOfPassion(A[], n) {
//	sum < -0;
//	for i < -1 to n - 1
//		for j < -i + 1 to n
//			sum < -sum + A[i] × A[j]; # 코드1
//			return sum;
//} 

int main()
{
	long long cnt;
	cin >> cnt;

	cout << cnt * (cnt - 1) / 2 << endl;
	cout << 2 << endl;

	return 0;
}