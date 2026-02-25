#include <iostream>

using namespace std;

bool isPrime(int num){
    if(num<2) return false;
    for(int i = 2; i*i <=num; i++){
        if(num%i == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, count = 0;
    cin >> N;

    for(int i =0; i < N; i++){
        cin >> num;
        if(isPrime(num)) count++;
    }
        
    cout << count << "\n";
    return 0;
}