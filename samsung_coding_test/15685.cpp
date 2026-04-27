#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int N;
int A[101][101]; //y x순으로만 해주면 문제될거 없 , 이건 지금 꼭짓점임.
int dr[] = {0, -1, 0, 1}; //동 북 서 남 방향 
int dc[] = {1, 0, -1 , 0};

int main(){
    cin >> N;
    int x,y,d,g;

    
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g; //첫번째 드래곤 정보 받음.
        vector<int> dirs;
        dirs.push_back(d); // 일단 받은 순서대로 push 하고 나중엔 뒤에서 부터 꺼내서 dir+1 한 곳에 붙인다.
        
        A[y][x] = 1; // 이게 내 시작점이다.
        for(int j=0; j<g; j++){
            int cur_size = dirs.size(); // 현재 몇번 이동해야하는지 저장
            for(int k = cur_size -1 ; k >= 0; k--){ //cur_size만큼 돌아야되긴해
                dirs.push_back(((dirs[k] + 1) % 4 )); //지금 받은 방향정보에 +1 한거
            }
        }
        for(int i=0; i<dirs.size(); i++){
            int dir = dirs[i];

            x += dc[dir];
            y += dr[dir];
            if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
                A[y][x] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // 네 꼭짓점이 모두 1인 1x1 칸을 찾음
            if (A[i][j] == 1 && A[i][j + 1] == 1 &&
                A[i + 1][j] == 1 && A[i + 1][j + 1] == 1) {
                answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}