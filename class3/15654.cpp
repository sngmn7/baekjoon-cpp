#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[10], num[10];
bool issued[10];

void dfs(int cnt){
    if (cnt == M){
        for (int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++){
        if (!issued[i]){
            arr[cnt] = num[i];
            issued[i] = true;
            dfs(cnt+1);
            issued [i] = false;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i<N; i++) cin >> num[i];
    sort(num, num+N);

    dfs(0);

    return 0;
}