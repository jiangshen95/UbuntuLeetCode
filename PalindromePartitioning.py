class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def partition(result, partitions, s):
            # print(partitions)
            for i in range(len(s)):
                l = 0
                r = i
                while l<r:
                    if s[l]!=s[r]:
                        break
                    l += 1
                    r -= 1
                if l>=r:
                    if i+1<len(s):
                        partitions += [s[:i+1]]
                        partition(result, partitions, s[i+1 :])
                        partitions.pop();
                    else:
                        result.append(partitions+[s[:i+1]])
                    
        result = []
        partitons = []
        partition(result, partitons, s)
        return result
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    result = solution.partition(s)
    print(result)
