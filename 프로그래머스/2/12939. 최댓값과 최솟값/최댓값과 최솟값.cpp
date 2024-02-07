#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    
    stringstream ss(s);
    string tmp;
    
    while(getline(ss, tmp, ' '))
        v.push_back(stoi(tmp));
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + " " + to_string(v.back());
    return answer;
}