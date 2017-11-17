class Interval:
    def __init__(self,s=0,e=0):
        self.start=s
        self.end=e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x:x.start)
        
        result=[]
        for interval in intervals:
            if len(result)==0 or (len(result)>0 and result[len(result)-1].end<interval.start):
                result.append(interval)
            else:
                result[len(result)-1].end = max(result[len(result)-1].end,interval.end)
        return result

if __name__=='__main__':
    n=int(input())
    
    intervals=[]
    for i in range(n):
        tem=input()
        interval=Interval(tem[0],tem[1])
        intervals.append(interval)
    
    solution=Solution()
    result=solution.merge(intervals)
    for i in result:
        print("%d, %d" % (i.start, i.end))
