# Saving Space - For DP
arr = [0]*3

#  In Loop
arr[2] = arr[0]+arr[1]
arr[0] = arr[1] # Shift
arr[1] = arr[2] # Idx 2 will get overwritten