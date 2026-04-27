#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N;
int board[505][505]; //모래정보 담아놓은 칸

//int dr[10] = {-1, 1, -1, 1, -1, -1, -2, 2, 0, 0};  
//int dc[10] = {1, 1, 0, 0, -1, 1, 0 , 0, -2, -1};
int dp[9] = {1, 1 , 7, 7, 10, 10, 2, 2, 5}; //퍼센트 값 저장
int dr2[] = {0, 1, 0, -1}; //서남동북 
int dc2[] = {-1, 0, 1, 0};
int ans = 0; //밖으로 나가는 먼지 양

int sdr[4][10], sdc[4][10]; // 4방향 x 10개 좌표

void init_rotate() {
    // 1. 서쪽(0번)은 승민이가 잡은 값 그대로 넣기
    int base_r[10] = {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}; //{-1, 1, -1, 1, -2, 2, -1, 1, 0, 0};
    int base_c[10] = {1, 1, 0, 0, -1, -1, 0 , 0, -2, -1}; //1, 1, 0, 0, 0, 0, -1, -1, -2, -1};
    
    for(int i=0; i<10; i++) {
        sdr[0][i] = base_r[i];
        sdc[0][i] = base_c[i];
    }

    // 2. 남(1), 동(2), 북(3) 방향은 이전 방향을 90도 돌려서 생성!
    for(int d=1; d<4; d++) {
        for(int i=0; i<10; i++) {
            // 반시계 회전 공식 적용: (r, c) -> (-c, r)
            sdr[d][i] = -sdc[d-1][i]; 
            sdc[d][i] = sdr[d-1][i];
        }
    }
}

void spread_dust(int r, int c, int d){ // 주변으로 먼지 spread하고, 밖으로 나가는 먼지양은 저장해두고
    int p = board[r][c]; // 현재 칸의 모래 정보 저장
    int total_spread = 0; //덮어 쓰는 변수 아닌이상 무조건 0으로 설정
    for(int i = 0; i<9; i++){
        int nr = r + sdr[d][i];
        int nc = c + sdc[d][i];

        int spread_amount =(p * dp[i]) / 100;

        if(nr < 1 || nr > N || nc < 1 || nc > N){
            ans += spread_amount;
        }
        else{
            board[nr][nc] += spread_amount;
        }   
        total_spread += spread_amount;
    }

    int ar = r + sdr[d][9];
    int ac = c + sdc[d][9];
    int alpha = p - total_spread;

    if(ar < 1 || ar > N || ac < 1 || ac > N){
        ans += alpha;
    }
    else{
        board[ar][ac] += alpha;
    }

    board[r][c] = 0;
    
}
int main(){
    cin >> N;
    init_rotate(); // 함수는 무조건 ()달아주기
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }

    int R = (N+1)/2, C = (N+1)/2;
    int dir = 0, dist = 1;

    while(true){ // 무한루프로 돌리고 안에서 탈출하는 게 제일 안전해
        for (int i = 0; i < 2; i++){
            for(int j = 0; j < dist; j++){
                R += dr2[dir]; // R, C를 바로 업데이트
                C += dc2[dir];

                spread_dust(R, C, dir);  

                if(R == 1 && C == 1){ // 1,1 도착하면 바로 출력하고 종료
                    cout << ans << "\n";
                    return 0;
                }
            }
            dir = (dir + 1) % 4;
        }
        dist++;
    }

    
    //모래 움직이는 방향에 따라 주변 모래 양 update
    //어디까지 움직이는지, 방향 언제 바뀌는지 체크
    //1,1 이 될때까지 반복
    //모래가 격자 밖을 나간양 cout
}