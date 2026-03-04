#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> unheard(N);
    for (int i = 0; i < N; i++) {
    cin >> unheard[i];
    }
    sort(unheard.begin(), unheard.end());

    vector<string> result;
    for (int i = 0; i < M; i++){
        string name;
        cin >> name;

        if (binary_search(unheard.begin(), unheard.end(), name)){
            result.push_back(name);

        }
    }
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}