#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
   
    while (true) {
        
        string str = "";
        stack<char> s;
        bool isPass = true;
   
        getline(cin, str, '.');

        if (str.empty() || (str.size() == 1 && str[0] == '\n')) { break; }

        for (auto c : str)
        {
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            
            else if (c == ')' || c == '}' || c == ']'){

                if (s.empty())
                {
                    isPass = false;
                    break;
                }

                if (c == ')' && s.top() == '(' ||
                    c == '}' && s.top() == '{' ||
                    c == ']' && s.top() == '[')
                    s.pop();

                else {  
                    isPass = false;
                    break;
                }
            }
        }

        if (s.empty() && isPass) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
