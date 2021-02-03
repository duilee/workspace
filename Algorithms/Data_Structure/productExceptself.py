## https://leetcode.com/problems/product-of-array-except-self/submissions/

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p = 1
        out = []

        for i in range(len(nums)):
            out.append(p)
            p *= nums[i]

        p = 1
        for i in range(len(nums) - 1, -1, -1):
            out[i] *= p
            p *= nums[i]

        return out
