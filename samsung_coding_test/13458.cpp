#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i<N ; i++) cin >> A[i];

    int B, C;
    cin >> B >> C;

    long long res = 0;

    for (int i = 0; i<N; i++){
        A[i] = A[i] - B;
        res += 1;

        if (A[i] <= 0) continue;

        int q = A[i] / C;
        if(A[i] % C == 0){
            res += q;
        }
        else{
            res = res + q + 1;
        }

    }

    cout << res << "\n";

    return 0;
}