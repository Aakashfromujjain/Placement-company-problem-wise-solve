#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v;
    long long weight;
    
    // Sort edges based on weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) structure
struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Every node is its own parent initially
        }
    }

    // Find with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

    // Union by rank
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true; // Successfully united
        }
        return false; // Cycle detected
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long min_cost = 0;
    int edges_used = 0;

    // Step 2: Iterate through sorted edges
    for (const auto& edge : edges) {
        // If including this edge doesn't cause a cycle, add it to MST
        if (dsu.unite(edge.u, edge.v)) {
            min_cost += edge.weight;
            edges_used++;
            
            // A spanning tree requires exactly n-1 edges
            if (edges_used == n - 1) break; 
        }
    }

    // Step 3: Check if we successfully formed a spanning tree
    if (edges_used == n - 1 || n == 1) { 
        cout << min_cost << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
