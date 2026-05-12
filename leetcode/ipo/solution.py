import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        projects = sorted(zip(capital, profits))
        heap = []
        i = 0
        n = len(projects)
        curr = w

        for _ in range(k):
            while i < n and projects[i][0] <= curr:
                heapq.heappush(heap, -projects[i][1])
                i += 1
            
            if not heap:
                break
            
            curr += -heapq.heappop(heap)

        return curr