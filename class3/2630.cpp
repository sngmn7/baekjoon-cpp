#include <iostream>
#include <vector>

using namespace std;

int paper[129][129];
int white = 0, blue = 0;

void solve(int y, int x, int n){
    int color = paper[y][x];
    bool same = true;

    for (int i = y; i < y + n; i++){
        for(int j = x; j < x + n ; j++){
            if (paper[i][j] != color){
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == 0) white ++;
        else blue++;
        return;
    }

    int next_n = n/2;

    solve(y, x, next_n);
    solve(y, x + next_n, next_n);
    solve(y + next_n, x ,next_n);
    solve(y + next_n, x + next_n, next_n);
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j =0; j < N; j++) cin >> paper[i][j];
    }

    solve(0,0,N);

    cout << white << "\n" << blue << "\n";
    return 0;
}