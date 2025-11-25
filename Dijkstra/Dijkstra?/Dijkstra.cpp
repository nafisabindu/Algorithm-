#include <bits/stdc++.h>

using namespace std;


using PII = pair<long long, int>;


const long long INF = 1e18;


void solve() {
    int n, m;

    if (!(cin >> n >> m)) return;


    vector<vector<PII>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }




    vector<long long> dist(n + 1, INF);

    vector<int> parent(n + 1, 0);


    priority_queue<PII, vector<PII>, greater<PII>> pq;


    dist[1] = 0;
    pq.push({0, 1});


    while (!pq.empty()) {

        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        if (d > dist[u]) {
            continue;
        }


        for (const auto& edge : adj[u]) {
            long long weight = edge.first;
            int v = edge.second;


            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }


    if (dist[n] == INF) {
        cout << -1 << endl;
        return;
    }


    vector<int> path;
    int curr = n;
    while (curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }


    reverse(path.begin(), path.end());


    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
