#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a<b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> v(N);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        if (i == 0 || v[i] != v[i-1]) {
            cout << v[i] << "\n";
        }
    }

    return 0;

}