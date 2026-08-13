#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long K;
    if (!(cin >> N >> K)) return 0;

    unordered_set<long long> present_ids;
    long long max_id = 0;

    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        if (val != -1) {
            present_ids.insert(val);
            max_id = max(max_id, val);
        }
    }

    // Search for the smallest distance d > 0 such that both (K - d) and (K + d) exist
    long long found_X = -1, found_Y = -1;
    
    // We only need to search until (K - d) becomes invalid (<= 0) 
    // or (K + d) exceeds the maximum ID present in the grid.
    for (long long d = 1; (K - d) > 0 && (K + d) <= max_id; ++d) {
        long long X = K - d;
        long long Y = K + d;

        if (present_ids.count(X) && present_ids.count(Y)) {
            found_X = X;
            found_Y = Y;
            break; // First pair found is guaranteed to be closest to K
        }
    }

    if (found_X != -1) {
        cout << found_X << " " << found_Y << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
