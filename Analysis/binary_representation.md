# Binary Representations
Problems utilizing binary representation of integers.


## Counting Bits (Leetcode 338)
Get the number of 1s in binary representation.

Case:
* i%2 == 0
    * ans[i] = ans[i//2]
    * Because x2 operation is just shift, so the number of bits is same
* i%2 != 0
    * ans[i] = ans[i-1] + 1
    * Just need to add 1