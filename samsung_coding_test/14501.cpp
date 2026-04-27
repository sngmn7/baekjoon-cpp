#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int T[16], P[16];
int max_profit = 0;

void solve(int day, int sum){
    if (day >= N+1 ){
        max_profit = max(max_profit, sum);
        return;
    }

    if (day + T[day] <= N+1){
        solve (day + T[day], sum + P[day]);
    }
    else{
        solve(day +1 , sum);
        return;
    }

    solve (day + 1, sum);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> P[i];
    }

    solve(1,0);

    cout << max_profit << "\n";

    return 0;

}