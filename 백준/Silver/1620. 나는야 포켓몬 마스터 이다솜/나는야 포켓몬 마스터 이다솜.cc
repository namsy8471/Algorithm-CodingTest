#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    vector<string> v1(n);
    unordered_map<string, int> stoiMap;

    vector<string> v2(m);

    for (int i = 0; i < n; i++)
    { 
        cin >> v1[i]; 
        stoiMap[v1[i]] = i;
    }

    for (int i = 0; i < m; i++) cin >> v2[i];
    

    for (auto& s : v2) {
        try {
            int stringToint = stoi(s) - 1;
            cout << v1[stringToint] << '\n';
        }
        catch (const exception) {

            int idx = stoiMap[s] + 1;
            cout << idx << '\n';
        }
    }
    

    return 0;
}