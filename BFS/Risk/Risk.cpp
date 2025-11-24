#include <bits/stdc++.h>

using namespace std;


const int NUM_COUNTRIES = 20;


int bfs_shortest_path(const vector<vector<int>>& adj, int start, int dest) {

    int start_node = start - 1;
    int dest_node = dest - 1;


    vector<int> distances(NUM_COUNTRIES, -1);


    queue<int> q;


    distances[start_node] = 0;
    q.push(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        if (current_node == dest_node) {

            return distances[dest_node] + 1;
        }

        for (int neighbor : adj[current_node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current_node] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}

bool solve_test_set(int test_set_num) {

    vector<vector<int>> adj(NUM_COUNTRIES);

    bool board_read = false;


    for (int i = 0; i < NUM_COUNTRIES - 1; ++i) {
        int num_connections;
        if (!(cin >> num_connections)) {

            if (i == 0 && test_set_num == 1) return false;

            return false;
        }
        board_read = true;

        int country_i = i;

        for (int k = 0; k < num_connections; ++k) {
            int country_j_1based;
            if (!(cin >> country_j_1based)) return false;


            int country_j = country_j_1based - 1;


            adj[country_i].push_back(country_j);
            adj[country_j].push_back(country_i);
        }
    }


    if (!board_read) return false;


    int N;
    if (!(cin >> N)) return false;

    cout << "          Test Set #" << test_set_num << endl;

    for (int i = 0; i < N; ++i) {
        int start_country, dest_country;
        if (!(cin >> start_country >> dest_country)) return false;
        int min_conquests = bfs_shortest_path(adj, start_country, dest_country);



        cout << setw(2) << right << start_country
             << " to "
             << setw(2) << right << dest_country
             << ": "
             << min_conquests << endl;
    }


    cout << endl;

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_set_count = 1;

    while (solve_test_set(test_set_count)) {
        test_set_count++;
    }

    return 0;
}
