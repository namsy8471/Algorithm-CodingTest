#include <string>
#include <vector>

using namespace std;

int answer = 0;
char c[] = {'A', 'E', 'I', 'O', 'U'};    
bool flag = false;

void DFS(string start, string dest, int depth)
{
    if(depth > 5) return;
    
    for(int i = 0; i < 5; i++)
    {
        string newWord = start + c[i];
        answer = flag ? answer : answer + 1;
        
        if(newWord == dest)
        {
            flag = true;
            return;
        }
        
        DFS(newWord, dest, depth + 1);
    }
}

int solution(string word) {
    
    DFS("", word, 1);
    flag = false;
    
    return answer;
}