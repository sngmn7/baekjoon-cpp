#include <iostream>
#include <vector>

using namespace std;
struct Shark { // 상어의 위치, 자신의 방향
    int r,c,dir; 
    bool alive = false;
};
Shark sharks[405];

struct Cell{ // 현재 냄새 번호 및 남은 시간
    int num; // 냄새 번호
    int time;
};
Cell board[21][21];

struct next_Move{
    int r,c,d; //상어 다음 위치, 방향 저장
};
next_Move next_move[405];

int N, M, K; // 격자 크기, 상어 수, k번 이후 냄새 삭제
int A[22][22]; //초기 상어 위치
int priority[402][5][5]; //상어의 번호, 방향, 방향에따른 우선순위 저장
int dr[] = {0,-1,1,0,0}; // 북 남 서 동 순
int dc[] = {0,0,0,-1,1};

void shark_move(){
    
    for (int i = 1; i<=M; i++){ //상어 횟수 만큼 반복. 상어 이동시키는 상황임. 모두 동시에 일어나야 함.
        //일단 상어 위치 저장해두고, 상어 달라진 방향 저장해두고, 냄새 -1 저장해둬야하고, 냄새 뿌려야함
        bool find = false;
        for(int j = 1; j<=4; j++){//아무 냄새 없는 칸 탐색
            if(sharks[i].alive == false) continue;
            int cur_dir = priority[i][sharks[i].dir][j];

            int nr = sharks[i].r + dr[cur_dir]; // 상어가 처음 이동할 위치.
            int nc = sharks[i].c + dc[cur_dir];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            if(board[nr][nc].num == 0){
                next_move[i].r = nr;
                next_move[i].c = nc;
                next_move[i].d = cur_dir;
                find = true;
                break; // 빈칸 찾으면 바로 멈추기
            }
        }
        for(int j = 1; j<=4; j++){// 자신 냄새 탐색
            if(find) break;
            //if(sharks[j].alive == false) continue;
            int cur_dir = priority[i][sharks[i].dir][j];

            int nr = sharks[i].r + dr[cur_dir]; // 상어가 처음 이동할 위치.
            int nc = sharks[i].c + dc[cur_dir];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            if(board[nr][nc].num == i){
                next_move[i].r = nr;
                next_move[i].c = nc;
                next_move[i].d = cur_dir;
                find = true;
                break;
            }
        }
    } //일단 이동 끝, 이전칸 -1 해줘야되고, 다음칸으로 이동시키고, 겹치는거 있음 죽이고 그 칸에 자기냄새 
    //그리고 위치 갱신.

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j].time -= 1; // 이전 보드에 있던 냄새 모두 -1.
            if(board[i][j].time == 0) board[i][j].num = 0; //냄새 없애기
        }
    } //이제 다음 위치로 상어 이동시키는데. 만약 그 칸에 다른 상어가 위치하고 있다면..죽이기

    int temp_board[22][22] = {0, };//모든 배열 0으로 초기화
    for(int i=1; i<=M; i++){ // 어차피 먼저 들어온 애가 젤 먼저 살게 됨. 이전 정보는 지워버리고 그냥 새로 sharks에 정보 넣는다고 생각하면 됨.
        if(sharks[i].alive == false) continue;

        int nr = next_move[i].r;
        int nc = next_move[i].c;
        int nd = next_move[i].d; // 상어의 모든 정보가 전달됨. 근데 이제 중복된 상어일 경우 죽여야돼, 그다음 자기 냄새 퍼뜨리기
        
        if(temp_board[nr][nc] == 0){
            temp_board[nr][nc] = i;
            sharks[i].r = nr;      // 실제 상어 위치 업데이트
            sharks[i].c = nc;
            sharks[i].dir = nd;
        }
        else{
            sharks[i].alive = false; // 나 죽이기.
        }
    }

    for(int i = 1; i <= M; i++) { //위치 들어간 애 냄새 뿌리기.
        if(sharks[i].alive) {
            board[sharks[i].r][sharks[i].c].num = i;
            board[sharks[i].r][sharks[i].c].time = K;
        }
    }
    //보드에 현재 냄새와 시간 남아있는데 이걸 바뀐 상어 위치랑 업데이트 해줘야함. 2개이상 위치가 중복되어 있을 수도 있다.
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int id;
            cin >> id; //현재 상어 위치에 상어 번호 저장. 0은 그냥 상어 없는 경우.
            if(id != 0){
                sharks[id].r=i;
                sharks[id].c=j;
                sharks[id].alive = true;
                board[i][j].num = id;
                board[i][j].time = K;
            }
        }
    }

    for(int i=1; i<=M; i++){
        cin >> sharks[i].dir; // 초기 상어 방향 받음.
    }

    for(int i=1; i<=M; i++){
        for(int j=1; j<=4; j++){
            for(int x = 1; x <=4; x++){
                cin >> priority[i][j][x]; //상어 번호, 상어 현재 방향, 상어 우선순위 저장
            }
        }
    }

    int time = 0; // 1000초 넘으면 -1 cout

    while(true){
        time++;
        if(time == 1001) { //1000초까진 시뮬레이션 돌려봐야함.
            cout << -1 << "\n";
            return 0;
        }
        shark_move();
        
        bool win = true; //bool로 확인.

        for(int i=2; i<=M; i++){
            if(sharks[i].alive){
                win = false;
                break; // 더이상 돌 필요 없음
            }
        }
        
        if(win){
            cout << time << "\n";
            return 0;
        }
    }
}