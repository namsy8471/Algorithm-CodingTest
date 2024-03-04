#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer(numbers.size(), -1);
    stack<int> indexStk;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        while(!indexStk.empty() && numbers[indexStk.top()] < numbers[i])
        {
            answer[indexStk.top()] = numbers[i];
            indexStk.pop();
        }
        
        indexStk.push(i);
    }
    
    return answer;
}