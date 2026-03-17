#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1005][1005];
int dist[1005][1005];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            dist[i][j] = -1;

            if (board[i][j] == 2){
                q.push({i,j});
                dist[i][j] = 0;
            } else if (board[i][j] == 0){
                dist[i][j] = 0;
            }
            
        }
    }

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >=0 && nx < n && ny >= 0 && ny < m ){
                if (board[nx][ny] == 1 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }

        }

    }
    
    for (int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
   
    return 0;

}