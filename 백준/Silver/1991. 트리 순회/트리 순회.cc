#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void preTraversal(unordered_map<char, pair<char, char>> um, char node)
{
    if (node == '.') return;

    cout << node;
    preTraversal(um, um[node].first);
    preTraversal(um, um[node].second);
}

void inTraversal(unordered_map<char, pair<char, char>> um, char node)
{
    if (node == '.') return;

    inTraversal(um, um[node].first);
    cout << node;
    inTraversal(um, um[node].second);
}

void postTraversal(unordered_map<char, pair<char, char>> um, char node)
{
    if (node == '.') return;

    postTraversal(um, um[node].first);
    postTraversal(um, um[node].second);
    cout << node;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int cnt;

    cin >> cnt;
    
    unordered_map<char, pair<char, char>> um;
    
    for (int i = 0; i < cnt; i++)
    {
        char root, left, right;

        cin >> root >> left >> right;

        um[root] = { left, right };
    }

    preTraversal(um, 'A');
    cout << '\n';
    inTraversal(um, 'A');
    cout << '\n';
    postTraversal(um, 'A');


    return 0;  
}