#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//북 동 남 서 순으로 설정
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int board[55][55];
struct Robot{
    int r, c, d;
};
Robot cleaner;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    cin >> cleaner.r >> cleaner.c >> cleaner .d ; //로봇 위치 입력받기 얘는 r,c를 0,0부터 줘서 r-- c--안해도 됨

    for(int i = 0; i <N; i++){
        for(int j = 0; j <M; j++){
            cin >> board[i][j];
        }
    }

    int cnt = 0;

    while(true){
        if (board[cleaner.r][cleaner.c] == 0){
            board[cleaner.r][cleaner.c] = 2;
            cnt++;
        }
        
        bool found = false; //일단 주변에 청소할 곳 있는지 찾기
        for (int i=0; i<4; i++){
            int nr = cleaner.r + dr[i];
            int nc = cleaner.c + dc[i];

            if(nr < 0 || nr >=N || nc < 0 || nc >= M) continue;

            if(board[nr][nc] == 0){
                found = true;
                break;
            }         
        }

        if(!found){
            int br = cleaner.r - dr[cleaner.d]; //후진 할 수 있는지 보기 cnt ++할 필요는 없다.
            int bc = cleaner.c - dc[cleaner.d];

            if(board[br][bc] == 1){
                cout << cnt << "\n";
                return 0;
            }

            cleaner.r = br;
            cleaner.c = bc;
        }

        if (found){
            cleaner.d = (cleaner.d + 3) % 4;

            int nr = cleaner.r + dr[cleaner.d];
            int nc = cleaner.c + dc[cleaner.d];

            if(board[nr][nc] == 0){
                cleaner.r = nr;
                cleaner.c = nc;
            }
        }
        
    }

}