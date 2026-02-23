#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    double sum = 0;
    double max_score = 0;
    double current_score = 0;

    for(int i = 0; i < N; i++){
        cin >> current_score;

        sum += current_score;

        if (current_score > max_score){
            max_score = current_score;
        }
    }

    sum = (sum/max_score * 100)/N;
    cout << fixed;
    cout.precision(2);   
    cout << sum << endl;

    return 0;
}