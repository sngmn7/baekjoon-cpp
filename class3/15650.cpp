#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[10];


void dfs(int num, int cnt){

    if(cnt == M){
        for (int i = 0; i < M; i ++) cout << arr[i] << " ";
        cout << "\n";
        return;
    
    }

    for (int i = num; i <= N; i++){
        arr[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}