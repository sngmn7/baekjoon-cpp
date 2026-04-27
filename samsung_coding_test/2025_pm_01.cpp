#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct New{
    int r1,c1,r2,c2; //현재 좌표
};

vector<New> news;

using namespace std;
int N, Q = 0;
int board[20][20]; // = {0, }; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Please write your code here.

    cin >> N >> Q; 

    int r1, c1, r2, c2;

    //news[i].r1, c1, r2, c2를 받아서 board에 넣어야함
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    for(int r = r1; r<=r2; r++){ //입력 받은애 일단 넣기
        for(int c = c1; c<=c2; c++){
            board[r][c] = 1;
        }
    }

    for(int r = 0; r<N; r++){ //입력 받은애 일단 넣기
        for(int c = 0; c<N; c++){
            cout << board[r][c] << "\n";
        }
    }

    // for (r = 0; )
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         board[i][j] = 0;
    //     }
    // }

    return 0;
}