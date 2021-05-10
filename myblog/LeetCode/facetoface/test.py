class Solution:
    def compressString(self, S: str) -> str:
        stack1 = [0]
        mid = 0
        lens = 0
        length = -2
        for i in S:
            if mid == i:
                lens +=1
            else:
                mid = i
                stack1.append(str(lens))
                lens=1
                stack1.append(i)
                length += 2
        stack1.append(str(lens))
        length += 2
        
        if length<len(S):
            s = ''.join(stack1[2:])
            return s
        return S 

s = Solution()

s1 ="aabcccccaaa"
s2 ="a2b1c5a3"

print(s.compressString(s1))

