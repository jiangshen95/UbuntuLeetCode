class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        
        result = []
        cur = []
        num_of_letters = 0
        
        for word in words:
            if num_of_letters + len(word) + len(cur) > maxWidth:
                for i in range(maxWidth-num_of_letters):
                    cur[i%(len(cur)-1 or 1)]+=' '
                result.append(''.join(cur))
                cur, num_of_letters = [], 0
            cur += [word]
            num_of_letters += len(word)
        for i in range(len(cur)-1):
            cur[i]+=' '
        result.append(''.join(cur)+' '*(maxWidth-num_of_letters-len(cur)+1))
        return result
        
if __name__=='__main__':
    n = int(input())
    maxWidth = int(input())
    words = []
    for i in range(n):
        word = raw_input()
        words.append(word)
    solution = Solution()
    print(solution.fullJustify(words, maxWidth))
