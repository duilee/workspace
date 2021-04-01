class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        result_list = []

        def dfs(elements, start, k):
            if k == 0:
                result_list.append(elements[:])
            else:
                for i in range(start, n + 1):
                    elements.append(i)
                    dfs(elements, i + 1, k - 1)
                    elements.pop()

        dfs([], 1, k)

        return result_list
