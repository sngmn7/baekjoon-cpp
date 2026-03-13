#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    long long high = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > high) high = trees[i]; 
    }

    long long low = 0;
    long long height = 0;

    while (low <= high){
        long long mid = (low+high) / 2;
        long long sum = 0;

        for(int i = 0; i < N; i++){
            if (trees[i] > mid){
                sum += (trees[i] - mid);
            }
        }
        
        if (sum >= M){
            height = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << height << "\n";
    return 0; 
}
