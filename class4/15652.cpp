#include <bits/stdc++.h>

using namespace std;
int arr[10];
int N,M;

void dfs(int start, int cnt){
    if (cnt == M) {
        for (int i = 0; i < M ; i++){
            cout << arr[i] << " ";
        }
            cout << "\n";
            return;
    }

    for (int i = start; i <= N ; i++){
        arr[cnt] = i;
        dfs(i, cnt+1);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dfs(1,0);

    return 0;
}