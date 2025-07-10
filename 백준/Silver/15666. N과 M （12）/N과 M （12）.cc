#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& ret, const vector<int>& v, int comb)
{
    if (ret.size() == comb)
    {
        for (auto& i : ret) cout << i << ' ';
        cout << '\n';
        
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (!ret.empty())
            if (ret.back() > v[i]) 
                continue;
        
        ret.push_back(v[i]);
        backtrack(ret, v, comb);
        ret.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int num, comb;

    cin >> num >> comb;

    vector<int> v(num);
    vector<int> result;

    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    backtrack(result, v, comb);

    return 0;  
}