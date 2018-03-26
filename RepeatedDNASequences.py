class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        hash_map = {}
        result = []
        for i in range(len(s)-9):
            w = s[i : i+10]
            if w in hash_map:
                if hash_map[w] == 1:
                    result.append(w)
                hash_map[w] += 1
            else:
                hash_map[w] = 1
        return result
            
            
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.findRepeatedDnaSequences(s))
