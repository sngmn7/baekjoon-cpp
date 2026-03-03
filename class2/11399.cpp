#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int total_sum = 0;
    int current_sum = 0;

    for (int i = 0; i < N; i++){
        current_sum += p[i];
        total_sum += current_sum;
    }

    cout << total_sum << "\n";

    return 0;
}