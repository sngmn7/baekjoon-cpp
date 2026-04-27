#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;

int N,M;
int board[102][102];
bool visited[102][102];
int dr[]= {0, 0, -1, 1};//상하좌우 방향
int dc[]= {-1, 1, 0, 0};

bool bfs(int r, int c){
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        if(curr.first == N-1 && curr.second == M-1){
            return true;
        }
        for(int i=0; i<4; i++){
            int cur_r = curr.first + dr[i];
            int cur_c = curr.second + dc[i];

            if(cur_r < 0 || cur_r >=N || cur_c < 0 || cur_c >= M) continue;

            if(visited[cur_r][cur_c] || board[cur_r][cur_c] == 0) continue;
            
            visited[cur_r][cur_c] = true;
            q.push({cur_r, cur_c});
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j]; //뱀은 ０, 빈칸은 １
        }
    }

    if (bfs(0, 0)){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }


    return 0;
}