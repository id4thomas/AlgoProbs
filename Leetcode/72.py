# Minimum Edit (insert, delete, replace)
# Levenshtein Dist

# https://en.wikipedia.org/wiki/Wagner–Fischer_algorithm
# Wagner-Fischer Algorithm

class Solution:
    # Wrong Answer
    # Considered LCS and in between

    # def minDistance(self, word1,word2):
    #     # print(self.lcs(word1,word2))
        
    #     checked = [[0]*(len(word2)+1) for i in range(len(word1)+1)]
        
    #     # word1 idx, word2 idx, lcs dist, edit dist, prev_w1_idx, prev_w2_idx
    #     queue = [(0,0,0,0,-1,-1)]
    #     max_len = 0
    #     # edit_dist = 0
    #     min_edit_dist = len(word1)+len(word2)
    #     # final_w1_idx = 0
    #     # final_w2_idx = 0
        
    #     while len(queue)>0:
    #         (i,j,cur_len,edit_dist,prev_w1_idx,prev_w2_idx) = queue.pop(0)
            
    #         if checked[i][j]!=0:
    #             continue
                
    #         # OOB
    #         if i>=len(word1) or j>=len(word2):
    #             # if max_len == cur_len:
    #             # final_w1_idx = prev_w1_idx
    #             # final_w2_idx = prev_w2_idx
    #             # print(max_len,cur_len,edit_dist)
    #             edit_dist += max(len(word1)-prev_w1_idx-1, len(word2)-prev_w2_idx-1)
    #             # print(max_len,cur_len,edit_dist)
    #             if min_edit_dist > edit_dist:
    #                 min_edit_dist = edit_dist
    #             continue
            
    #         checked[i][j]=1
            
    #         if word1[i] == word2[j]:
    #             # Update Edit dist
    #             # print(word1[i],edit_dist,max(i-prev_w1_idx-1,j-prev_w2_idx-1))
    #             edit_dist += max(i-prev_w1_idx-1, j-prev_w2_idx-1)
    #             # print(edit_dist)
                
    #             # Update Prev Idx
    #             prev_w1_idx = i
    #             prev_w2_idx = j
                
    #             # Update LCS Dist
    #             if max_len < cur_len+1:
    #                 max_len = cur_len+1
                    
    #             queue.append((i+1,j+1,cur_len+1,edit_dist,prev_w1_idx,prev_w2_idx))
                
    #         else:
    #             queue.append((i,j+1,cur_len,edit_dist,prev_w1_idx,prev_w2_idx))
    #             queue.append((i+1,j,cur_len,edit_dist,prev_w1_idx,prev_w2_idx))
                
    #     print("Fin",max_len,min_edit_dist)
    #     # min_edit_dist += max(len(word1)-final_w1_idx-1, len(word2)-final_w2_idx-1)
    #     print(min_edit_dist)

    #     return min_edit_dist

    def minDistance(self, word1,word2):
        # print(self.lcs(word1,word2))
        
        dist = [[0]*(len(word2)+1) for i in range(len(word1)+1)]

        for i in range(1,len(word1)+1):
            dist[i][0]=i
        for j in range(1,len(word2)+1):
            dist[0][j]=j
        
        for i in range(1,len(word1)+1):
            for j in range(1,len(word2)+1):
                if word1[i-1]==word2[j-1]:
                    sub_cost = 0
                else:
                    sub_cost = 1
                
                dist[i][j] = min(dist[i-1][j]+1, dist[i][j-1]+1, dist[i-1][j-1]+sub_cost)
        print(dist[len(word1)][len(word2)])                
        return dist[len(word1)][len(word2)]

        
# 3
word1 = "horse"
word2 = "ros"
Solution().minDistance(word1,word2)

# 5
word1 = "intention"
word2 = "execution"
Solution().minDistance(word1,word2)

# 6
word1 = "industry"
word2 = "interest"
Solution().minDistance(word1,word2)

# 30
word1 = "pneumonoultramicroscopicsilicovolcanoconiosis"
word2 = "stereomicroscopically"
Solution().minDistance(word1,word2)
