#include <iostream>
#include <string>

using namespace std;

int stack_arr[10000];

int top_idx = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while(N--){
        string cmd;
        cin >> cmd;

        if (cmd == "push"){
            int x;
            cin >> x;
            stack_arr[++top_idx] = x;
        }
        else if (cmd == "pop"){
            if (top_idx == -1){
                cout << -1 << "\n";
            }
            else {
                cout << stack_arr[top_idx--] << "\n";
            }
            
        }
        else if (cmd == "size") {
            cout << top_idx + 1 << "\n";
        }
        else if (cmd == "empty"){
            if (top_idx == -1){
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else if (cmd == "top"){
            if (top_idx == -1){
                cout << -1 << "\n";
            }
            else {
                cout << stack_arr[top_idx] << "\n";
            }
        }
        
    }

    return 0;

}