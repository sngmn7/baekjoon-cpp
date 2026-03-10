#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end;
};

bool compare(Meeting a, Meeting b){
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Meeting> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), compare);

    int count = 0;
    int now = 0;

    for (int i = 0; i < N; i++){
        if (v[i].start >= now){
            now = v[i].end;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}