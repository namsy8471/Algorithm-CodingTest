#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int haveCnt, needCnt;

    cin >> haveCnt >> needCnt;

    vector<long long> v(haveCnt, 0);
    long long maxLen = 0;

    for (auto& i : v) {
        cin >> i;
        if (i > maxLen)
            maxLen = i;
    }

    long long left = 1;
    long long right = maxLen;
    long long result = 0;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (mid == 0) mid = 1;

        long long cnt = 0;
        for (auto i : v) cnt += i / mid;

        if (cnt >= needCnt)
        {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << result;

    return 0;  
}