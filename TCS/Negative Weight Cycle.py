class Solution:
    def isNegativeWeightCycle(self, V: int, edges: list[list[int]]) -> bool:
        # code heredef isNegativeWeightCycle(self, V: int, edges: list[list[int]]) -> bool:
                   from collections import deque
                   dist = [0] * V
                   path_len = [0] * V
                   adj = [[] for _ in range(V)]
                   for u, v, w in edges:
                       adj[u].append((v, w))
                   q = deque(range(V))
                   in_queue = [True] * V
                   while q:
                       u = q.popleft()
                       in_queue[u] = False
                       for v, w in adj[u]:
                           if (d := dist[u] + w) < dist[v]:
                               path_len[v] = path_len[u] + 1
                               if path_len[v] == V:
                                   return True
                               dist[v] = d
                               if not in_queue[v]:
                                   q.append(v)
                                   in_queue[v] = True
                   return False
