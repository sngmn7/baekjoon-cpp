#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, 1, -1};
int N,M;
queue<pair<int,int>> q;

void bfs(){
    while (!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >=0 && nx < N && ny >=0 && ny <M){
                if (board[nx][ny] == 0 && dist[nx][ny] == -1 ){
                    dist[nx][ny] = dist[curr.first][curr.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            dist[i][j] = -1;

            if (board[i][j] == 1){
                dist[i][j] = 0;
                q.push({i, j});                
            }
        }
    }

    bfs();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && dist[i][j] == -1){
                cout << -1 <<"\n";
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << "\n";
    return 0;
}