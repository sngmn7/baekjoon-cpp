#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> cards(N);

    for (int i = 0; i<N; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());
    
    cin >> M;
    
    for (int i = 0; i<M; i++){
        int target;
        cin >> target;

        auto low = lower_bound(cards.begin(), cards.end(), target);
        auto up = upper_bound(cards.begin(), cards.end(), target);

        cout << up - low << " ";
    }

    return 0;

}