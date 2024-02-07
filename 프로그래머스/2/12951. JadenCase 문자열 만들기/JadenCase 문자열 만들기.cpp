#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirstChar = true;
    
    
    for(auto& c : s)
    {
        if(c == ' ')
        {
            isFirstChar = true;
            continue;
        }
        
        if(isFirstChar)
        {
            if(islower(c) != 0) c = toupper(c);
            isFirstChar = false;
            continue;
        }
        
        else
        {
            if(isupper(c) != 0) c = tolower(c);
        }
    }
    
    return s;
}