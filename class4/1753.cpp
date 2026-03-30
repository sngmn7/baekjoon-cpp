#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int V,E,K;
vector<pair<int,int>> adj[20001];
int dist[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < d) continue;

        for (auto &edge : adj[curr]){
            int next = edge.first;
            int weight = edge.second;

            if(dist[next] > dist[curr] + weight){
                dist[next] = dist [curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;

    fill(dist, dist + V + 1, INF);

    for (int i = 0; i < E ; i++){
        int u, v, w;
        cin >> u, v, w;
        adj[u].push_back({v,w});
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++){
        if (dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;

}