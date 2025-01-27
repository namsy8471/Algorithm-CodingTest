#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    
    int cnt;

    cin >> cnt;

    vector<int> v(cnt);

    for (int i = 0; i < cnt; i++) cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> dist(cnt - 1);
    for (int i = 0; i < cnt - 1; i++) dist[i] = v[i + 1] - v[i];

    int all_gcd = dist[0];

    for (int i = 1; i < cnt - 1; i++) all_gcd = gcd(all_gcd, dist[i]);

    int ret = 0;
    for (auto i : dist) ret += (i / all_gcd) - 1;
    
    cout << ret;

    return 0;
}