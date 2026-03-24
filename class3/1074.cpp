#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void solve(int n, int r, int c){
    if (n==0) return;

    int half = 1 << (n-1);

    if (r < half && c < half){
        solve(n-1, r, c);
    }

    else if (r < half && c >= half){
        ans += half * half;
        solve(n - 1, r ,c - half);
    }

    else if (r >= half && c < half){
        ans += 2*half*half;
        solve(n-1, r-half, c);
    }

    else if (r >= half && c >= half){
        ans += 3*half*half;
        solve(n-1, r-half, c-half);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    if (!(cin >> N >> r >> c)) return 0;

    solve(N,r,c);

    cout << ans << "\n";

    return 0;
}