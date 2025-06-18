#include <iostream>  
#include <vector>
#include <utility>

using namespace std;

pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return { a.first + b.first, a.second + b.second };
}

pair<int, int> countPapers(int sH, int eH, int sW, int eW, vector<vector<int>>& v)
{
    int firstColor = v[sH][sW];
    bool isAllSame = true;

    for (int i = sH; i <= eH; i++)
    {
        for (int j = sW; j <= eW; j++)
        {
            if (v[i][j] != firstColor) { 
                isAllSame = false; 
                break;
            }
        }
    }

    if (isAllSame)
    {
        if (v[sH][sW] == 1)
            return { 0, 1 };
        else
            return { 1, 0 };
    }
    
    int midH = sH + (eH - sH) / 2;
    int midW = sW + (eW - sW) / 2;

    pair<int, int> topLeft = countPapers(sH, midH, sW, midW, v);
    pair<int, int> topRight = countPapers(sH, midH, midW + 1, eW, v);
    pair<int, int> bottomLeft = countPapers(midH + 1, eH, sW, midW, v);
    pair<int, int> bottomRight = countPapers(midH + 1, eH, midW + 1, eW, v);

    return topLeft + topRight + bottomLeft + bottomRight;
}

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int n;

    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    pair<int, int> ret = countPapers(0, n - 1, 0, n - 1, v);
    cout << ret.first << '\n' << ret.second;

    return 0;  
}
