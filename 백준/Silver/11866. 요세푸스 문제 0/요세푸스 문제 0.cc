#include <iostream>
#include <vector>

using namespace std;

void solveJosephus(int n, int k)
{
    vector<int> v;
    vector<bool> isBanned(n, false);

    v.push_back(k);
    isBanned[k - 1] = true;

    for (int i = k; v.size() < n;)
    {
        for (int rep = 0; rep < k; rep++)
        {
            i++;
            if (n < i) i -= n;

            while (isBanned[i - 1]) {
                i++;
                if (n < i) i -= n;
            }
        }

        v.push_back(i);
        isBanned[i - 1] = true;
    }

    cout << '<' << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cout << ", " << v[i];
    }
    cout << '>';
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;
 
    solveJosephus(n, k);

    return 0;
}
