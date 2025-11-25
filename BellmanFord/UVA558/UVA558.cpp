#include <bits/stdc++.h>

using namespace std;

struct Wormhole {
    int start;
    int end;
    int time_diff;
};

const long long INF = 1e18;

bool hasNegativeCycle(int N, int M, const vector<Wormhole>& wormholes) {
    vector<long long> dist(N, INF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; ++i) {
        bool updated = false;

        for (const auto& w : wormholes) {
            if (dist[w.start] != INF) {
                if (dist[w.start] + w.time_diff < dist[w.end]) {
                    dist[w.end] = dist[w.start] + w.time_diff;
                    updated = true;
                }
            }
        }

        if (!updated) {
            break;
        }
    }

    for (const auto& w : wormholes) {
        if (dist[w.start] != INF) {
            if (dist[w.start] + w.time_diff < dist[w.end]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    while (C--) {
        int N, M;
        if (!(cin >> N >> M)) break;

        vector<Wormhole> wormholes(M);
        for (int i = 0; i < M; ++i) {
            cin >> wormholes[i].start >> wormholes[i].end >> wormholes[i].time_diff;
        }

        if (hasNegativeCycle(N, M, wormholes)) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }

    return 0;
}

