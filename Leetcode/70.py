# https://leetcode.com/problems/climbing-stairs/

# You are climbing a staircase. It takes n steps to reach the top.

# Each time you can either climb 1 or 2 steps. 
# In how many distinct ways can you climb to the top?

from math import comb

class Solution:
    # def climbStairs(self, n: int) -> int:
    def climbStairs(self, n):
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
        
        print(k)

        return
# 2
n = 2
Solution().climbStairs(n)

# 3
n = 3
Solution().climbStairs(n)

n = 5
Solution().climbStairs(n)