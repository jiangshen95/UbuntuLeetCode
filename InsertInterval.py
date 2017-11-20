class Interval:
    def __init__(self, s=0, e=0):
        self.start=s
        self.end=e
        
class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        left = [i for i in intervals if i.end<newInterval.start]
        right = [i for i in intervals if i.start>newInterval.end]
        
        if left+right!=intervals:
            newInterval.start = min(intervals[len(left)].start, newInterval.start)
            newInterval.end = max(intervals[len(intervals)-len(right)-1].end, newInterval.end)
        return left+[newInterval]+right
        
if __name__=='__main__':
    n=int(input())
    
    intervals=[]
    for i in range(n):
        tem=input()
        interval=Interval(tem[0],tem[1])
        intervals.append(interval)
        
    tem=input()
    newInterval=Interval(tem[0], tem[1])
    
    solution=Solution()
    result=solution.insert(intervals, newInterval)
    for i in result:
        print("%d, %d" % (i.start, i.end))
        
