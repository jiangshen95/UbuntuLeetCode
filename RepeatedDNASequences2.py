class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        hash_map = {}
        result = []
        for i in range(len(s)-9):
            v = 0
            for j in range(i, i+10):
                # (ord(s[j]) - ord('A') + 1)%5  A C G T 分别为1 3 2 0
                v  = v<<2 | (ord(s[j]) - ord('A') + 1)%5
            if v in hash_map:
                if hash_map[v] == 1:
                    result.append(s[i : i+10])
                hash_map[v] += 1
            else:
                hash_map[v] = 1
        return result
            
            
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.findRepeatedDnaSequences(s))
