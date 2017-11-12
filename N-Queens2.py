class Solution:
    def solveNQueens(self, n):
        def DFS(queens,xy_dif,xy_sum):
            p=len(queens)
            if p==n:
                result.append(queens)
                return None
            for i in range(n):
                if i not in queens and p-i not in xy_dif and p+i not in xy_sum:
                    DFS(queens+[i],xy_dif+[p-i],xy_sum+[p+i])
        result=[]
        DFS([],[],[])
        return [["."*i+"Q"+"."*(n-i-1) for i in sol] for sol in result]

if __name__=="__main__":
    n=int(input())
    solution=Solution()
    result=solution.solveNQueens(n)
    print(result)

