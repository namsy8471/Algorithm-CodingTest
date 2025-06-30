#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> fruit(n);

    for (int i = 0; i < n; i++)
        cin >> fruit[i];

    int start = 0;
    int max_len = 0;
    map<int, int> fruit_counter;

    for (int end = 0; end < n; end++)
    {
        fruit_counter[fruit[end]]++;

        while (fruit_counter.size() > 2)
        {
            int start_fruit = fruit[start];
            fruit_counter[start_fruit]--;

            if (fruit_counter[start_fruit] == 0)
                fruit_counter.erase(start_fruit);

            start++;
        }

        max_len = max(max_len, end - start + 1);
    }

    cout << max_len << endl;

    return 0;  
}