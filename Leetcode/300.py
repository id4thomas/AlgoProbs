# https://leetcode.com/problems/longest-increasing-subsequence/
# Given an integer array nums, return the length of the longest strictly increasing subsequence.

# A subsequence is a sequence that can be derived from an array by deleting some or no elements 
# without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

# https://www.youtube.com/watch?v=cjWnW0hdF1Y&t=975s
# O(n^2) DP Solution

class Solution:
    # def lengthOfLIS(self, nums: List[int]) -> int:
    def lengthOfLIS(self, nums):
        max_lens = [0]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            max_lens[i]=1
            for j in range(i+1,len(nums)):
                if nums[i]<nums[j] and max_lens[i] < (1+ max_lens[j]):
                    max_lens[i] = 1 + max_lens[j]
        print(max(max_lens))

# 4
input1 = [10,9,2,5,3,7,101,18]

# 4
input2 = [0,1,0,3,2,3]

# 1
input3 = [7,7,7,7,7,7,7]

Solution().lengthOfLIS(input1)
Solution().lengthOfLIS(input2)
Solution().lengthOfLIS(input3)