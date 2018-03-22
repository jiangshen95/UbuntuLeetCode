class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        levels1 = version1.split('.')
        levels2 = version2.split('.')
        
        for i in range(max(len(levels1), len(levels2))):
            gap = (int(levels1[i]) if i<len(levels1) else 0) - (int(levels2[i]) if i<len(levels2) else 0)
            if gap > 0:
                return 1
            elif gap<0:
                return -1
        return 0
        
if __name__=='__main__':
    version1 = raw_input()
    version2 = raw_input()
    
    solution = Solution()
    print(solution.compareVersion(version1, version2))
