#include <iostream>
#include <string>
#include <stack>

using namespace std;

string checkVPS(){
    string str;
    cin >> str;

    stack<char> s;

    for (char c : str){
        if (c == '('){
            s.push(c);
        }
        else{
            if(!s.empty()){
                s.pop();
            }      
            else{
                return "NO";
            }
        }
    }
    if (s.empty()) return "YES";
    else return "NO";
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        cout << checkVPS() <<"\n";
    }

    return 0;
}