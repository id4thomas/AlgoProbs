# https://leetcode.com/problems/longest-common-subsequence/

# Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
# A subsequence of a string is a new string generated from the original string with some characters (can be none) 
# deleted without changing the relative order of the remaining characters.
# For example, "ace" is a subsequence of "abcde".
# A common subsequence of two strings is a subsequence that is common to both strings.

# https://www.youtube.com/watch?v=Ua0GhsJSlWM

class Solution:
    def longestCommonSubsequence(self, text1, text2):
        lcs_len = 0
        
        check_q = [(0,0,0)]
        
        checked = [[0]*(len(text2)+1) for i in range(len(text1)+1)]
        
        while len(check_q)>0:
            (i, j, cur_len) = check_q.pop(0)
            if checked[i][j]!=0 or i>=len(text1) or j>=len(text2):
                continue
            checked[i][j] = 1
                
            if text1[i] == text2[j]:
                # Update
                if lcs_len < cur_len+1:
                    lcs_len = cur_len+1
                # Move Diagonally
                check_q.append((i+1,j+1,cur_len+1))
            else:
                check_q.append((i+1,j,cur_len))
                check_q.append((i,j+1,cur_len))
                
        # print(lcs_len)
        return lcs_len
        
# # 3
# text1 = "abcde"
# text2 = "ace"
# Solution().longestCommonSubsequence(text1,text2)

# # 3
# text1 = "abc"
# text2 = "abc"
# Solution().longestCommonSubsequence(text1,text2)

# # 0
# text1 = "abc"
# text2 = "def"
# Solution().longestCommonSubsequence(text1,text2)

# text1 = "oxcpqrsvwf"
# text2 = "shmtulqrypy"
# Solution().longestCommonSubsequence(text1,text2)

text1 = "ylqpejqbalahwr"
text2 = "yrkzavgdmdgtqpg"
Solution().longestCommonSubsequence(text1,text2)

text1 = "pneumonoultramicroscopicsilicovolcanoconiosis"
text2 = "stereomicroscopically"
print(Solution().longestCommonSubsequence(text1,text2))