#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L;
int A[102][102];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    int ans = 0;

    // 1. 행 순회
    for (int r = 0; r < N; r++) {
        bool isPossible = true;
        int cnt = 1; // 첫 번째 칸(c=0)을 포함하므로 1
        int now = A[r][0];

        for (int c = 1; c < N; c++) {
            if (now == A[r][c]) {
                cnt++;
            } 
            else if (now + 1 == A[r][c]) { // 오르막
                if (cnt >= L) {
                    now = A[r][c];
                    cnt = 1; // 새로운 칸부터 다시 1
                } else {
                    isPossible = false; break;
                }
            } 
            else if (now - 1 == A[r][c]) { // 내리막
                int sn = 1;
                for (int i = c + 1; i < N; i++) {
                    if (sn == L) break;
                    if (A[r][i] == A[r][c]) sn++;
                    else break; // 높이가 다를 때만 멈춤!
                }
                if (sn < L) {
                    isPossible = false; break;
                } else {
                    c = c + L - 1; 
                    now = A[r][c];
                    cnt = 0; // 내리막 끝 지점은 0으로 초기화
                }
            } 
            else { // 차이 1 초과
                isPossible = false; break;
            }
        }
        if (isPossible) ans++;
    }

    // 2. 열 순회
    for (int r = 0; r < N; r++) {
        bool isPossible = true;
        int cnt = 1;
        int now = A[0][r];

        for (int c = 1; c < N; c++) {
            if (now == A[c][r]) {
                cnt++;
            } 
            else if (now + 1 == A[c][r]) { // 오르막
                if (cnt >= L) {
                    now = A[c][r];
                    cnt = 1;
                } else {
                    isPossible = false; break;
                }
            } 
            else if (now - 1 == A[c][r]) { // 내리막
                int sn = 1;
                for (int i = c + 1; i < N; i++) {
                    if (sn == L) break;
                    if (A[i][r] == A[c][r]) sn++;
                    else break; // 높이가 다를 때만 멈춤!
                }
                if (sn < L) {
                    isPossible = false; break;
                } else {
                    c = c + L - 1;
                    now = A[c][r];
                    cnt = 0;
                }
            } 
            else {
                isPossible = false; break;
            }
        }
        if (isPossible) ans++;
    }

    cout << ans << "\n";
    return 0;
}