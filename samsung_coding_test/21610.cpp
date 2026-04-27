#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Place{
    int r,c; //좌표
    int d,s; // 방향, 거리
    int water; // 물의 양
};

vector<Place> places;

int N,M;
int board[54][54]; // N*N 보드 칸 넘어가는거 잡아주도록 나눗셈? 나머지 해줘야함
int cloud[54][54]; // 현재 구름 위치 표시
int dr[] = {0,0,-1,-1,-1,0,1,1,1}; //서쪽부터 8가지 방향 설정
int dc[] = {0,-1,-1,0,1,1,1,0,-1};
bool check[54][54]; // 구름 있었던 위치 저장하기 위해.. 초기값은 false

void move(){
    vector<pair<int, int>> clouds; // 구름 많아지면 자동으로 추가 될 수 있도록 vector 사용
    
    clouds.push_back({N, 1});
    clouds.push_back({N, 2});
    clouds.push_back({N - 1, 1});
    clouds.push_back({N - 1, 2});

    for (int k=0; k<M; k++){
        bool check[54][54] = {false, }; // 2차원 배열을 초기화 해줄때는 {false, }나 {0, } 해줘야함

        for (int i=0; i <clouds.size(); i++){ //방향 이동하고 구름 +1, 구름이였던 곳 저장
            //bool check[54][54] = {false, }; //이렇게해야 다음 시작할때 구름 위치 리셋. 모든 칸을 false.
            int d=places[k].d;
            int s=places[k].s;

            int r = clouds[i].first; // 현재위치들
            int c = clouds[i].second;//
            
            int nr = (r + dr[d] * s) % N; //대신 이동할때 한계 넘으면 다음으로 넘어갈 수 있게 코드 쨔야함
            if(nr <=0) nr += N; // 음수일땐 N더해서 보정
            int nc = (c + dc[d] * s) % N;
            if(nc <=0) nc += N;

            clouds[i].first = nr;
            clouds[i].second = nc;

            board[nr][nc] ++; // 구름 +1
            check[nr][nc] = true; // 5번을 위해 3번 구름 위치 저장

            //여기서 clouds는 초기화 하지 말기 4번 물복사버그에서 사용할 가능성 많다
        }

        for (int i = 0; i<clouds.size(); i++){
            int r = clouds[i].first; // 현재위치들
            int c = clouds[i].second;
            int count = 0; // 항상 변수 0으로 받아주기
            for(int d = 2; d <9; d +=2){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr<1||nr>N||nc<1||nc>N) continue;

                if (board[nr][nc] > 0) count++;
            }

            board[r][c] += count;
        }

        clouds.clear();
        for (int i = 1; i<= N; i++){
            for (int j = 1; j<=N; j++){
                if (board[i][j] >= 2 && !check[i][j]){ //false일때 구름 생성
                    board[i][j] -= 2;
                    clouds.push_back({i,j}); //여기선 {}로 pair를 push back 한다.
                } 
            }
        }

    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M; //N은 박스 크기, M은 이동 횟수
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j]; //보드에 현재 물 양 정리  시발 cin 해줘야 보드가 채워지지
        }
    }

    for (int i = 0; i<M; i++){
        int d_input, s_input;
        cin >> d_input >> s_input;
        Place temp;
        temp.d = d_input;
        temp.s = s_input;
        places.push_back(temp); // 움직여야할 방향, 거리 저장
    }

    move();

    int result = 0; //int result만 하면 이상한값 들어감. 항상 0으로 초기화해주기
    for (int i = 1; i <=N; i++){
        for (int j=1; j<=N; j++){
            result += board[i][j];
        }
    }

    cout << result << "\n";

    return 0;
}