#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;

        for (int j = K; j>=w; j--){
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }

    cout << dp[K] << "\n";

    return 0;
}