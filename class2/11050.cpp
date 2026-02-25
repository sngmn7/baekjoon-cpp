#include <iostream>

using namespace std;

int factorial(int n){
    int result = 1;

    for(int i = 1; i <= n; i++){
        result *= (i);
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << factorial(N) / (factorial(K)*factorial(N-K)) << "\n";
}