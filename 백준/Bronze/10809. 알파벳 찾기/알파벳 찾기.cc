#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string S;
    cin >> S;
    int check[26];
    for (int i = 0; i < 26; i++){
        check[i] = -1;
    }
    for (int i = 0; i < S.length(); i++){
        if(check[S[i] - 'a'] != -1)
            continue;
        check[S[i] - 'a'] = i;
    }
    
    for (int i = 0; i < 26; i++)
        cout << check[i] << " ";
}