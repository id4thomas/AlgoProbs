# https://leetcode.com/problems/climbing-stairs/

# You are climbing a staircase. It takes n steps to reach the top.

# Each time you can either climb 1 or 2 steps. 
# In how many distinct ways can you climb to the top?

from math import comb

class Solution:
    # def climbStairs(self, n: int) -> int:
    # Don't use combination equations
    def climbStairs_bad(self, n):
        # 1 or 2
        # 3: 1,2 / 2,1 / 1,1,1
        # 5: 2,2,1 / 2,1,2 / 1,2,2 / 2,2,1,1,1 /
        
        # Only 1s
        climb_count = 1
        
        k = n//2
        count_pos = k
        if n%2!=0:
            count_pos+=1
        
        for i in range(k,0,-1):
            climb_count += comb(count_pos,i)

        return
    
    def climbStairs(self, n):
        if n<3:
            return n
        
        # Only use O(1) memory
        arr = [0]*3
        
        arr[0] = 1
        arr[1] = 2
        
        for i in range(2,n):
            arr[2] = arr[0] + arr[1]
            
            # Overwrite
            arr[0] = arr[1]
            arr[1] = arr[2]
            
        return arr[2]
# 2
n = 2
Solution().climbStairs(n)

# 3
n = 3
Solution().climbStairs(n)

n = 5
Solution().climbStairs(n)