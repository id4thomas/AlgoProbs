# https://leetcode.com/problems/trapping-rain-water/
# Given n non-negative integers representing an elevation map 
# where the width of each bar is 1, 
# compute how much water it can trap after raining.

# https://www.youtube.com/watch?v=ZI2z5pq0TqA&t=662s

# Time O(n), Memory O(n)

class Solution:
    # def trap(self, height: List[int]) -> int:
    def trap(self, height):
        # Get L,R max heights
        l_maxs = [0] * len(height)
        r_maxs = [0] * len(height)
        
        l_max = 0
        r_max = 0
        for i in range(len(height)):
            l_maxs[i] = l_max
            r_maxs[i] = r_max
            
            if l_max < height[i]:
                l_max = height[i]
                
            if r_max < height[len(height)-i-1]:
                r_max = height[len(height)-i-1]
            
        r_maxs.reverse()
        
        # Calc Block for each position
        rain = 0
        for i in range(len(height)):
            rain += max([0,min([l_maxs[i],r_maxs[i]])-height[i]])
        # print(rain)
        return rain
        
# 6
input1 = [0,1,0,2,1,0,1,3,2,1,2,1]

# 9
input2 = [4,2,0,3,2,5]

print(Solution().trap(input1))
print(Solution().trap(input2))