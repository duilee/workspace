class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        result_list = []

        def dfs(nums, comb):
            if len(nums) == 0:
                result_list.append(comb)
                return
            else:
                for i in range(len(nums)):
                    nums_c = nums.copy()
                    nums_c.pop(i)  # or remove(i)
                    dfs(nums_c, comb + [nums[i]])

        dfs(nums, [])

        return result_list

