#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> v1;
    vector<string> v2;
    
    for(auto& c : str1) c = toupper(c);
    for(auto& c : str2) c = toupper(c);
    
    for(int i = 0; i < str1.length() - 1; i++)
    {
        if(isalpha(str1[i]) == 0 || isalpha(str1[i+1]) == 0) continue;
        v1.push_back(str1.substr(i, 2));
    }
    
    
    for(int i = 0; i < str2.length() - 1; i++)
    {
        if(isalpha(str2[i]) == 0 || isalpha(str2[i+1]) == 0) continue;
        v2.push_back(str2.substr(i, 2)); 
    }
    
    vector<string> unionVec(v1.size() + v2.size());
    vector<string> interSectionVec(v1.size() + v2.size());
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), unionVec.begin());
    unionVec.erase(it, unionVec.end());
    
    it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), interSectionVec.begin());
    interSectionVec.erase(it, interSectionVec.end());
    
    if(interSectionVec.empty() && unionVec.empty()) return 65536;
    
    return (int)((float)interSectionVec.size() / (float) unionVec.size() * 65536);
}