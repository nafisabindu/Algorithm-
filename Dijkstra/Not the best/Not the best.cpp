#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int weight;
};

long long solve() {
    int N, R;
    if (!(cin >> N >> R)) return -1;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> d1(N + 1, INF);
    vector<long long> d2(N + 1, INF);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    d1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > d2[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long w = edge.weight;
            long long new_d = d + w;

            if (new_d < d1[v]) {
                d2[v] = d1[v];
                d1[v] = new_d;
                pq.push({d1[v], v});
                if (d2[v] != INF) pq.push({d2[v], v});
            }
            else if (new_d > d1[v] && new_d < d2[v]) {
                d2[v] = new_d;
                pq.push({d2[v], v});
            }
        }
    }

    return d2[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        long long result = solve();
        cout << "Case " << t << ": " << result << "\n";
    }

    return 0;
}
