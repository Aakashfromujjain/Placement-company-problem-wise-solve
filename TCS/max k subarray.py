import heapq
import sys

def solve():
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    K = int(input_data[1])
    arr = list(map(int, input_data[2:]))
    
    # Precompute prefix sums for O(1) subarray sum calculation
    # sum(arr[i:j+1]) = prefix_sum[j+1] - prefix_sum[i]
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i+1] = prefix_sum[i] + arr[i]
        
    # Max-heap to store (-sum, start_index, end_index)
    # We use negative sum because Python's heapq is a min-heap
    pq = []
    
    # Since all elements are >= 0, for any start i, 
    # the largest sum is the longest possible subarray [i, N-1]
    for i in range(N):
        current_sum = prefix_sum[N] - prefix_sum[i]
        heapq.heappush(pq, (-current_sum, i, N - 1))
        
    total_k_sum = 0
    count = 0
    
    while pq and count < K:
        neg_s, i, j = heapq.heappop(pq)
        total_k_sum += (-neg_s)
        count += 1
        
        # If we just took [i, j], the next largest for start i is [i, j-1]
        if j > i:
            next_sum = prefix_sum[j] - prefix_sum[i]
            heapq.heappush(pq, (-next_sum, i, j - 1))
            
    print(total_k_sum)

if __name__ == "__main__":
    solve()
