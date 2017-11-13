class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def solve(total,col,sum_xy,dif_xy):
            row=len(col)
            for i in range(n):
                if i not in col and row+i not in sum_xy and row-i not in dif_xy:
                    if row==n-1:
                        total[0]+=1
                    else:
                        solve(total,col+[i],sum_xy+[row+i],dif_xy+[row-i])
        total=[0]
        solve(total,[],[],[])
        return total[0]
        
if __name__=='__main__':
    n=int(input())
    solution=Solution()
    print(solution.totalNQueens(n))
