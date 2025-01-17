#include <iostream>
#include <cmath>

using namespace std;

//MenOfPassion(A[], n) {
//    sum < -0;
//    for i < -1 to n - 2
//        for j < -i + 1 to n - 1
//            for k < -j + 1 to n
//                sum < -sum + A[i] × A[j] × A[k]; # 코드1
//                return sum;
//}

int main()
{
	long long cnt;
	cin >> cnt;

	cout << cnt * (cnt - 1) * (cnt - 2) / 6 << endl;
	cout << 3 << endl;

	return 0;
}