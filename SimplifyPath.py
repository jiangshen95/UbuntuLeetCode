class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        paths = path.split("/")
        dirs = []
        for p in paths:
            if p=='..':
                if len(dirs)>0:
                    dirs.pop()
            elif p!='.' and p!='':
                dirs.append(p)
        return '/'+'/'.join(dirs)
        
if __name__=='__main__':
    path = raw_input()
    solution = Solution()
    print(solution.simplifyPath(path))
