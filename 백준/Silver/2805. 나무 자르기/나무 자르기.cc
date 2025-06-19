#include <iostream>  
#include <vector>

using namespace std;

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int numOfTree, len;

    cin >> numOfTree >> len;

    vector<int> v(numOfTree, 0);
    
    long long low = 0;
    long long high = 0;

    for (auto& iter : v)
    {
        cin >> iter;
        if (iter > high) high = iter;
    }

    long long sum = 0;
    int ret = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        sum = 0;

        for (int i = 0; i < v.size(); i++)
            sum += v[i] - mid > 0 ? v[i] - mid : 0;

        if (sum >= len)
        {
            ret = mid;
            low = mid + 1;
        }
        else if (sum < len)
            high = mid - 1;
    }
    
    cout << ret;

    return 0;  
}
