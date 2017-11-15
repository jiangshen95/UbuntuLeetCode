class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result=[]
        if len(matrix)<=0:
            return result
        y_left, y_right = 0, len(matrix[0])-1
        x_top, x_below = 0, len(matrix)-1
        
        while y_left<=y_right and x_top<=x_below:
            for i in range(y_left,y_right+1):
                result.append(matrix[x_top][i])
            for i in range(x_top+1,x_below+1):
                result.append(matrix[i][y_right])
            if y_left<y_right and x_top<x_below:
                for i in range(y_right-1,y_left-1,-1):
                    result.append(matrix[x_below][i])
                for i in range(x_below-1,x_top,-1):
                    result.append(matrix[i][y_left])
            y_left+=1
            y_right-=1
            x_top+=1
            x_below-=1
            
        return result
        
if __name__=='__main__':
    m=int(input())
    nums=[]
    for i in range(m):
        line=input()
        nums+=[list(line)]
    
    solution=Solution()
    result=solution.spiralOrder(nums)
    print(result)
