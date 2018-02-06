class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        front = set([beginWord])
        back = set([endWord])
        unvisited = set(wordList)
        unvisited.discard(beginWord)
        
        if not unvisited & back:
            return 0
        
        step = 1
        
        while front:
            front = unvisited & (set(word[:i]+ch+word[i+1:] for word in front for i in range(len(word)) for ch in 'abcdefghijklmnopqrstuvwxyz' ))
            step += 1
            if front & back:
                return step
            if len(front)>len(back):
                front, back = back, front
            unvisited -= front
        return 0
            
if __name__=='__main__':
    beginWord = raw_input()
    endWord = raw_input()
    n = int(raw_input())
    wordList = []
    for i in range(n):
        word = raw_input()
        wordList.append(word)
    solution = Solution()
    print(solution.ladderLength(beginWord, endWord, wordList))
