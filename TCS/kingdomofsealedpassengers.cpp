#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];       // Original graph
vector<int> rev_adj[MAXN];   // Reversed graph
bool visited[MAXN];
stack<int> finish_stack;
int scc_id[MAXN];            // Stores which SCC each node belongs to

// Pass 1: standard DFS to populate the stack based on finish times
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    finish_stack.push(u);
}

// Pass 2: DFS on the reversed graph to identify SCCs
void dfs2(int u, int current_scc) {
    visited[u] = true;
    scc_id[u] = current_scc;
    for (int v : rev_adj[u]) {
        if (!visited[v]) {
            dfs2(v, current_scc);
        }
    }
}

int main() {
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    // Step 1: Fill the stack with nodes by finish time
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Process nodes in order of decreasing finish time to find SCCs
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    
    int num_scc = 0;
    while (!finish_stack.empty()) {
        int u = finish_stack.top();
        finish_stack.pop();
        
        if (!visited[u]) {
            num_scc++;
            dfs2(u, num_scc);
        }
    }

    // Step 3: Calculate the in-degree of each SCC
    vector<int> in_degree(num_scc + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                in_degree[scc_id[v]]++;
            }
        }
    }

    // Step 4: Count SCCs with in-degree 0
    int zero_in_degree_count = 0;
    for (int i = 1; i <= num_scc; i++) {
        if (in_degree[i] == 0) {
            zero_in_degree_count++;
        }
    }

    cout << zero_in_degree_count << "\n";

    return 0;
}
