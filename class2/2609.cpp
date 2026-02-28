#include <iostream>

using namespace std;

int get_gcd(int N, int M){
    if (M==0) return N;
    return get_gcd(M, N % M);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    cout << get_gcd(N,M) <<"\n" << (N * M) / get_gcd(N,M) << "\n";

    return 0;
}