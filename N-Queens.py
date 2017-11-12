class Solution:
    def solveNQueens(self, n):
        def solve(result,board,row,n):
            for i in range(n):
                if board[row][i]=='.' and isValid(board,row,i,n):
                    board[row]=board[row][:i]+'Q'+board[row][i+1:]
                    if row==n-1:
                        one=[]
                        one+=board
                        result.append(one)
                    else:
                        solve(result,board,row+1,n)
                    board[row]=board[row][:i]+'.'+board[row][i+1:]
					
        def isValid(board,x,y,n):
            for i in range(n):
                if board[x][i]!='.':
                    return False
                if board[i][y]!='.':
                    return False
                if i+(y-x)>=0 and i+(y-x)<n and board[i][i+(y-x)]!='.':
                    return False
                if n-i-1-(n-x-y-1)>=0 and n-i-1-(n-x-y-1)<n and board[i][n-i-1-(n-x-y-1)]!='.':
                    return False
            return True
			
        result=[]
        board=["."*n]*n
        solve(result,board,0,n)
        return result
		
if __name__=="__main__":
    n=int(input())
    solution=Solution()
    result=solution.solveNQueens(n)
    print(result)
