#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    int mixed = -1;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto i : scoville) pq.push(i);

    while(1 < pq.size() && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        mixed = first + second * 2;
        answer++;
        pq.push(mixed);
    }
    
    if(pq.top() < K) answer = -1;
    
    return answer;
}