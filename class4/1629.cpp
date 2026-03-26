#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b, long long c){
    if (b==1) return a % c;

    long long temp = solve(a, b/2, c);

    temp = (temp * temp) % c;

    if (b%2 ==0){
        return temp;
    } else{
        return (temp * a) % c;
    }
}

int main(){
    long long a,b,c;
    cin >> a >> b >>  c;

    cout << solve(a,b,c) << "\n";

    return 0;
}