#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<string> unheard;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        unheard.insert(name); 
    }

    set<string> result;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;

        if (unheard.find(name) != unheard.end()){
            result.insert(name);
        }
    }
   
    cout << result.size() << "\n";
    for (const string& name : result) {
        cout << name << "\n";
        }

    return 0;

}