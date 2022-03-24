# https://leetcode.com/problems/word-break/
# Given a string s and a dictionary of strings wordDict, 
# return true if s can be segmented into a space-separated sequence 
# of one or more dictionary words.

# that the same word in the dictionary may be reused multiple times in the segmentation.

# Time: O(m*n) - Only check each position Once
class Solution:
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    def wordBreak(self, s, wordDict):
        len_dict = {}

        # Group by word length
        for word in wordDict:
            word_len = len(word)
            if word_len not in len_dict.keys():
                len_dict[word_len]=[word]
            else:
                len_dict[word_len].append(word)

        queue = [0] 
        checked = [0]*len(s)
        
        # Use Stack
        while len(queue)>0:
            i = queue.pop()
            # i = queue.pop(0)
            
            # Finishing Condition
            if i>=len(s):
                return True
            
            # Only Check each position Once
            if checked[i]!=0:
                continue
            checked[i]=1
            
            for j in len_dict.keys():
                if s[i:i+j] in len_dict[j]:
                    queue.append(i+j)
        return False
        
        
        
# true
s = "leetcode"
wordDict = ["leet","code"]
print(Solution().wordBreak(s,wordDict))

# true
s = "applepenapple"
wordDict = ["apple","pen"]
print(Solution().wordBreak(s,wordDict))

# false
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
print(Solution().wordBreak(s,wordDict))

s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
print(Solution().wordBreak(s,wordDict))