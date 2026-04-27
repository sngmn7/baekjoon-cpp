#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Parcel {
    int k; //택배번호
    int r,c;
    int h,w; //세로, 가로
    bool out;
};
vector<Parcel> parcels;

int N, M;
int board [54][54];

void updateBoard(Parcel &p, int val){
    for (int i = p.r; i < p.r + p.h; i++) {
        for (int j = p.c; j < p.c + p.w; j++) {
            board[i][j] = val; // 그냥 깔끔하게 0으로 밀어버리기!
        }
    }
}

void dropParcel(Parcel &p){
    if (p.out) return;

    int final_r = p.r;

    while (true) {
        int test_r = final_r + 1;
        bool can_go = true;

        if(test_r + p.h -1 >= N) can_go = false;
        else{
            for(int j = p.c; j < p.c + p.w; j++){
                if(board[test_r + p.h -1][j] != 0){
                    can_go = false;
                    break;
                }
            }
        }

        if (can_go) final_r = test_r;
        else break;
    }

    if(final_r != p.r || board[p.r][p.c] == 0){
        if(board[p.r][p.c] != 0) updateBoard(p, 0); // 기존 위치 지우기
        p.r = final_r;
        updateBoard(p, p.k); // 새 위치 그리기
    }


}

bool canExit(Parcel &p, bool isLeft){
    if(p.out) return false;

    if (isLeft){ // 왼쪽 체크 (0번 열까지)
        for(int i = p.r; i < p.r + p.h; i++){
            for(int j = 0; j < p.c; j++){
                if (board[i][j] != 0) return false;
            }
        }
    }
    else { // 오른쪽 체크 (N-1번 열까지)
        for (int i = p.r; i < p.r + p.h; i++){
            // ★ 시작점: 내 오른쪽 끝(p.c + p.w)
            // ★ 끝점: 격자 전체 너비(N)
            for (int j = p.c + p.w; j < N; j++){ 
                if (board[i][j] != 0) return false;
            }
        }
    }
    return true;
}

//일다 이거부터 작성

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // 입출력 속도 향상
    if (!(cin >> N >> M)) return 0; //입력 안 들어온 경우

    // 1. 택배 입력 및 순차적 투입
    for (int i = 0; i < M; i++) {
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        c--; // 0-indexed로 변경
        parcels.push_back({k, 0, c, h, w, false});
        dropParcel(parcels.back());
    }

    // 2. 하차 시도를 위해 택배 번호(k) 순으로 정렬
    sort(parcels.begin(), parcels.end(), [](Parcel a, Parcel b) {
        return a.k < b.k;
    });

    // 3. M번의 하차 기회
    for (int t = 0; t < M; t++) {
        bool isLeft = (t % 2 == 0);

        // 번호가 작은 택배부터 하차 가능한지 검사
        for (int i = 0; i < M; i++) {
            if (parcels[i].out) continue;

            if (canExit(parcels[i], isLeft)) {
                // 하차 성공!
                cout << parcels[i].k << "\n";
                parcels[i].out = true;
                updateBoard(parcels[i], 0);

                // ★ 연쇄 중력: 더 이상 움직이는 박스가 없을 때까지 반복
                while (true) {
                    bool changed = false;
                    for (int row = N - 1; row >= 0; row--) {
                        for (int col = 0; col < N; col++) {
                            if (board[row][col] != 0) {
                                int target_k = board[row][col];
                                for (int idx = 0; idx < M; idx++) {
                                    if (!parcels[idx].out && parcels[idx].k == target_k) {
                                        int old_r = parcels[idx].r;
                                        dropParcel(parcels[idx]);
                                        if (old_r != parcels[idx].r) changed = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (!changed) break; // 더 이상 움직임이 없으면 while 탈출
                }
                break; // 하차 성공했으니 이번 턴(t) 종료, 다음 턴으로!
            }
        }
    }

    return 0;
}