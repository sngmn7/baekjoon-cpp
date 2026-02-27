#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    
    while (cin >> s && s != "0"){
        string original = s;

        reverse(s.begin(), s.end());

        if (original == s) cout << "yes\n";

        else cout << "no\n";      
    }

}