#include <bits/stdc++.h>
using namespace std;

int dist[100005];
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(n);
    dist[n] = 0; 

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == k) {
            cout << dist[curr] << "\n";
            return 0;
        }

      
        int next_pos[3] = {curr - 1, curr + 1, curr * 2};

        for (int i = 0; i < 3; i++) {
            int nx = next_pos[i];

            if (nx >= 0 && nx <= 100000 && dist[nx] == -1) {
                dist[nx] = dist[curr] + 1; 
                q.push(nx);
            }
        }
    }

    return 0;
}