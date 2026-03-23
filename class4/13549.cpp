#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 1e9;

int dist[MAX];

int dijkstra(int start, int target){
    typedef pair<int, int> pii; 

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    fill(dist, dist+100001, INF);
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int cur_time = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_time) continue;

        if (cur_node * 2 < MAX && dist[cur_node * 2] > cur_time){
            dist[cur_node * 2] = cur_time;
            pq.push({cur_time, cur_node * 2});
        }

        if (cur_node + 1 < MAX && dist[cur_node + 1] > cur_time + 1){
            dist[cur_node + 1] = cur_time+1;
            pq.push({cur_time+1, cur_node + 1});
        }

        if (cur_node - 1 >= 0 && dist[cur_node - 1] > cur_time + 1){
            dist[cur_node - 1] = cur_time+1;
            pq.push({cur_time+1, cur_node - 1});
        }
    }
    return dist[target];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;

    cout << dijkstra(N,K) << "\n";

    return 0;

}   
