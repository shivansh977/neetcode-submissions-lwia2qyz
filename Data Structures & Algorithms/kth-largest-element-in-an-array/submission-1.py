import heapq;

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        tmp = []
        for v in nums:
            if len(tmp) < k:
                heapq.heappush(tmp, v)
            elif v>tmp[0]:
                heapq.heappop(tmp)
                heapq.heappush(tmp, v)
        return tmp[0]