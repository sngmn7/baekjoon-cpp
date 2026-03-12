#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int parent[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i<N-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;

    q.push(1);
    parent[1] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : adj[curr]){
            if (parent[next] == 0){
                parent[next] = curr;
                q.push(next);
            }
        }
    }
    for(int i = 2; i<=N; i++){
        cout << parent[i] << "\n";
    }
    return 0;
}