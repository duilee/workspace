# https://leetcode.com/problems/top-k-frequent-elements/

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs = collections.Counter(nums)
        freqs_heap = []
        # insert as neg integer
        for f in freqs:
            heapq.heappush(freqs_heap, (-freqs[f], f))

        topk = list()
        # pop k times
        for _ in range(k):
            topk.append(heapq.heappop(freqs_heap)[1])

        return topk


"""
list(zip(*collections.Counter(nums).most_common(k)))[0]
"""
