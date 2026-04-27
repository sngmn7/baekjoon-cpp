#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct Dust{
    int r,c,val; // 현재 먼지 위치, 값 저장
};
vector<Dust> dusts;

int R,C,T;
int A[54][54]; // 먼지 정보 + 로봇 정보 저장할 방
int dr[] = {0, 0, 1, -1}; 
int dc[] = {1, -1, 0 ,0}; // 동서남북 순으로 저장

int main(){
    cin >> R >> C >> T; // R과 C는 row와 column이다
    R--; C--;

    vector<int> air_cleaner; // air_cleaner.first 하면 로봇 위쪽 위치가 나옴.

    for (int r = 0; r <= R ; r++){
        for (int c = 0; c <= C; c++){
            cin >> A[r][c]; // 공기청정기 정보 = -1, 나머지는 먼지 정보 저장
            if (A[r][c] == -1) air_cleaner.push_back(r);
        }
    }

    for(int k = 0; k < T; k++){
            //무조건 동시에 발생해야함
            //하나씩 탐색해서 만약에 먼저 있다면 걔 기준 동서남북 탐색하고. 확산 횟수 저장해주고. 확산 시키고. 확산된만큼 빼주고
        int next_A [54][54] = {0, };

        for (int r = 0; r <= R; r++){
            for (int c = 0; c<=C; c++){
                if(A[r][c] > 0){
                    int num = 0;
                    for(int d = 0; d<4; d++){      
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(nr < 0 || nr > R || nc < 0 || nc > C || A[nr][nc] == -1) continue;
                        next_A[nr][nc] += A[r][c] / 5;
                        num++;
                    }
                    next_A[r][c] += A[r][c] - num * (A[r][c] / 5);    
                }

                else if (A[r][c] == -1){
                    next_A[r][c] = -1;
                    //air_cleaner.push_back(r);
                }
            }
        }

        memcpy(A,next_A,sizeof(A)); // A를 바뀐걸로 갱신

        int dx1[] = {1, 0, -1, 0}; //동북서남 순
        int dy1[] = {0, -1, 0, 1};

        
        int cur_R = air_cleaner[0]; // 현재 로봇 위치
        int cur_C = 1;
        int cur_val = 0;
        int next_val = 0;
        int dir = 0;
        
        //범위 구하기 어려운 경우에는 while문 쓰자
        while(true){

            if (A[cur_R][cur_C] == -1) break;
            
            next_val = A[cur_R][cur_C];
            //다음값 저장
            //현재값 다음 칸에 저장
            //다음값을 현재 값으로
            A[cur_R][cur_C] = cur_val;
            cur_val = next_val;

            int nr = cur_R + dy1[dir];
            int nc = cur_C + dx1[dir];

            if (nr < 0 || nr > air_cleaner[0] || nc < 0 || nc > C){
                dir++;
                nr = cur_R + dy1[dir];
                nc = cur_C + dx1[dir];
            }
            cur_R = nr;
            cur_C = nc;
        }

        int dx2[] = {1, 0, -1, 0}; //동남서북 순
        int dy2[] = {0, 1, 0, -1};

        
        int cur_R2 = air_cleaner[1]; // 현재 로봇 위치
        int cur_C2 = 1;
        int cur_val2 = 0;
        int next_val2 = 0;
        int dir2 = 0;
        
        //범위 구하기 어려운 경우에는 while문 쓰자
        while(true){

            if (A[cur_R2][cur_C2] == -1) break;
            
            next_val2 = A[cur_R2][cur_C2];
            //다음값 저장
            //현재값 다음 칸에 저장
            //다음값을 현재 값으로
            A[cur_R2][cur_C2] = cur_val2;
            cur_val2 = next_val2;

            int nr2 = cur_R2 + dy2[dir2];
            int nc2 = cur_C2 + dx2[dir2];

            if (nr2 > R || nr2 < air_cleaner[1] || nc2 < 0 || nc2 > C){
                dir2++;
                nr2 = cur_R2 + dy2[dir2];
                nc2 = cur_C2 + dx2[dir2];
            }
            cur_R2 = nr2;
            cur_C2 = nc2;
        }

    }

    int total_dust = 0;
    for (int r = 0; r <= R; r++) {
        for (int c = 0; c <= C; c++) {
            if (A[r][c] > 0) { // 먼지가 있는 칸만 더하기 (-1 제외)
                total_dust += A[r][c];
            }
        }
    }

    cout << total_dust << "\n"; // 결과 출력!

    return 0;
        //시작 위치는 A[air_cleaner.first][1], c-1번만큼 얘를 next_A[air_cleaner.first][i]칸으로 옮기면서 새로 쓰기
        //그다음 r-1만큼 [air_cleaner.first][i-1]만큼 옮기기.
        //그다음 [air_clearn.first - i] [i] 만큼 옮기고
        //r-1만큼 [air_cleaner.first] [i-1] 만크 옮기기
        //그냥 이러지말고 C에 닿으면 위쪽으로, 또 막히면 왼쪽으로 또 막히면 위쪽으로 이런식으로 코드 실행      
            //이제 공기청정기가 돌면서 먼지를 한칸씩 밀어버리고 전체 미세먼지의 양 get
}