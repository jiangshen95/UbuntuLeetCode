class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        left = [0]*(len(heights))
        right = [0]*(len(heights))
        stack = [0]*(len(heights))
        
        s = 0
        for i in range(len(heights)):
            while s>0 and heights[i]<=heights[stack[s-1]]:
                s -= 1
            left[i] = 0 if s==0 else stack[s-1]+1
            stack[s] = i
            s += 1
        
        s = 0
        for i in range(len(heights)-1, -1, -1):
            while s>0 and heights[i]<=heights[stack[s-1]]:
                s -= 1
            right[i] = len(heights) if s==0 else stack[s-1]
            stack[s] = i
            s += 1
        
        largest = 0
        area = 0
        for i in range(len(heights)):
            area = (right[i]-left[i])*heights[i]
            print(area)
            if area>largest:
                largest = area
        return largest
        
if __name__=='__main__':
    heights = list(input())
    solution = Solution()
    print(solution.largestRectangleArea(heights))
