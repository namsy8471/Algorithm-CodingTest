#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int rnd = round(v.size() * 0.15);

    int sum = 0;
    for (int i = rnd; i < n - rnd; i++)
        sum += v[i];

    if(n > 0) sum = round((float)sum / (v.size() - (rnd * 2)));

    cout << sum;

    return 0;
}


