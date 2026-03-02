#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < N; i++){
        cout << points[i].first << " " << points[i].second << "\n";
    }

    return 0;

}