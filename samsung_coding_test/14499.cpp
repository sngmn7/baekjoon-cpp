#include <iostream>
#include <vector>
using namespace std;

int board[25][25];
int N,M,x,y,k; // x,y는 주사위 놓을 좌표, k는 명령어 갯수 x,y는 -- 필요
int dr[] = {0, 0, -1, 1}; //동서북남 순 column임.
int dc[] = {1, -1, 0, 0};
int dice[] = {0 , 0, 0, 0, 0, 0, 0}; //1번이 젤 위. 6이 젤 아래, 첨 주사위는 0

int main(){
    cin >> N >> M >> x >> y >> k; // xy는 진짜 좌표임. x가 row y가 column
    

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j]; // 
        }
    }

    int cur_R = x; // y값
    int cur_C = y; // x값

    for(int i=0; i<k; i++){ //k번 반복
        int K; //현재 입력 받은 방향 정보
        cin >> K; // 입력 받은 방향
        
        int nr = cur_R + dr[K-1];
        int nc = cur_C + dc[K-1];

        if(nr < 0 || nr >=N || nc < 0 || nc >=M) continue;
        
        if(K == 1){
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }
        else if (K == 2){
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }
        else if (K==3){
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        else if (K==4){
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }

        if(board[nr][nc] == 0){ //바닥이 0이면 주사위 값 복사
            board[nr][nc] = dice[6]; 
        }
        else {
            dice[6] = board[nr][nc]; // 바닥에 값이 있어면 칸 -> 주사위, 칸 0
            board[nr][nc] = 0;
        }

        cur_R = nr;
        cur_C = nc;

        cout << dice[1] << "\n";
    }

    return 0;
}




