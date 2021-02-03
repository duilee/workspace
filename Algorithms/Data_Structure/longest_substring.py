# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = {}
        max_len = start = 0
        for index, char in enumerate(s):
            # if already in used, change start
            if char in used and start <= used[char]:
                start = used[char] + 1
            else: # update max_len
                max_len = max(max_len, index - start + 1)

            # set current index
            used[char] = index

        return max_len
