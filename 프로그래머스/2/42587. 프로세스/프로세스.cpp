#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int,int>> v;
    queue <pair<int,int>> q;
    
    for(int i = 0; i < 9; i++) v.push_back(make_pair(i + 1, 0));
    for(int i = 0; i < priorities.size(); i++) q.push(make_pair(priorities[i], i));
    
    for(int i = 0; i < priorities.size(); i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(v[j].first == priorities[i])
            {
                v[j].second++;
                break;
            }
        }
    }

    v.erase(remove_if(v.begin(), v.end(),
                      [](const pair<int, int>& p) { return p.second == 0; }), v.end());
    sort(v.rbegin(), v.rend());
    
    for(int i = 0; i < v.size();)
    {
        while(true)
        {
            if(v[i].first == q.front().first)
            {
                if(q.front().second == location) return answer + 1;
                
                answer++;
                v[i].second--;
            }
            else
                q.push(q.front());
            
            q.pop();
            
            if(v[i].second == 0) i++;
            if(i >= v.size()) break;
        }
    }
    
    return answer;
}