class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.append(-1)
        stack = []
        largest = 0
        
        i = 0
        while i<len(heights):
            if len(stack)==0 or (len(stack)>0 and heights[i]>=heights[stack[-1]]):
                stack.append(i)
                i += 1
            else:
                top = stack[-1]
                stack.pop()
                area = 0
                if len(stack)==0:
                    area = heights[top]*i
                else:
                    area = heights[top]*(i-stack[-1]-1)
                print(area)
                if area>largest:
                    largest = area
        return largest
        
if __name__=='__main__':
    heights = list(input())
    solution = Solution()
    print(solution.largestRectangleArea(heights))
