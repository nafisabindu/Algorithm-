#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int source;
    int destination;
    long long weight;

    Edge(int u, int v, long long w) : source(u), destination(v), weight(w) {}
};

int n;
vector<int> busyness;
vector<Edge> edges;

const long long INF = 1e18;

long long calculate_cost(int u, int v) {
    long long diff = (long long)busyness[v] - busyness[u];
    return diff * diff * diff;
}

void bellman_ford(int start_node, vector<long long>& min_costs) {
    min_costs.assign(n + 1, INF);
    min_costs[start_node] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            long long w = edge.weight;

            if (min_costs[u] != INF && min_costs[u] + w < min_costs[v]) {
                min_costs[v] = min_costs[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            long long w = edge.weight;

            if (min_costs[u] != INF && min_costs[u] + w < min_costs[v]) {
                min_costs[v] = -INF;
            }
        }
    }
}

void solve_case(int set_num) {
    busyness.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!(cin >> busyness[i])) return;
    }

    int r;
    if (!(cin >> r)) return;
    edges.clear();

    for (int i = 0; i < r; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return;
        long long cost = calculate_cost(u, v);
        edges.emplace_back(u, v, cost);
    }

    vector<long long> min_costs;
    bellman_ford(1, min_costs);

    int q;
    if (!(cin >> q)) return;

    cout << "Set #" << set_num << endl;

    for (int i = 0; i < q; ++i) {
        int query_node;
        if (!(cin >> query_node)) return;

        long long min_earning = min_costs[query_node];

        if (min_earning == INF || min_earning < 3 || min_earning == -INF) {
            cout << "?" << endl;
        } else {
            cout << min_earning << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int set_num = 1;

    while (cin >> n) {
        if (n == 0) {
            if (n == 0) {
                 int r_dummy, q_dummy;
                 cin >> r_dummy;
                 for (int i = 0; i < r_dummy; ++i) {
                     int u_dummy, v_dummy;
                     cin >> u_dummy >> v_dummy;
                 }
                 cin >> q_dummy;
                 cout << "Set #" << set_num++ << endl;
                 for(int i = 0; i < q_dummy; ++i) {
                     int node_dummy;
                     cin >> node_dummy;
                     cout << "?" << endl;
                 }
                 continue;
            }
        }
        solve_case(set_num++);
    }

    return 0;
}
