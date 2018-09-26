class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class SummaryRanges:

    class BSTNode:
        def __init__(self, val):
            self.interval = val
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        def findMin(root):
            if not root:
                return None
            if not root.left:
                return root
            return findMin(root.left)

        def remove(root, interval):
            if not root:
                return None
            if interval.start > root.interval.end:
                root.right = remove(root.right, interval)
            elif interval.end < root.interval.start:
                root.left = remove(root.left, interval)
            else:
                if root.left and root.right:
                    root.interval = findMin(root.right).interval
                    root.right = remove(root.right, root.interval)
                else:
                    root = root.left if root.left else root.right
            return root

        def findKey(root, val):
            if not root:
                return None
            elif val > root.interval.end:
                return findKey(root.right, val)
            elif val < root.interval.start:
                return findKey(root.left, val)
            else:
                return root

        def addNum(root, val):
            if not root:
                root = self.BSTNode(Interval(val, val))
            elif val > root.interval.end:
                root.right = addNum(root.right, val)
            elif val < root.interval.start:
                root.left = addNum(root.left, val)
            return root

        if not self.root:
            self.root = addNum(self.root, val)
        else:
            if findKey(self.root, val):
                return
            left = findKey(self.root, val - 1)
            right = findKey(self.root, val + 1)
            if not left and not right:
                self.root = addNum(self.root, val)
            elif left and not right:
                left.interval.end += 1
            elif not left and right:
                right.interval.start -= 1
            else:
                e = right.interval.end
                self.root = remove(self.root, right.interval)
                left.interval.end = e

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        def inOrder(root):
            if not root:
                return
            inOrder(root.left)
            intervals.append(root.interval)
            inOrder(root.right)

        intervals = []
        inOrder(self.root)
        return intervals


if __name__ == '__main__':
    summary = SummaryRanges()
    num = int(input())
    while num != -1:
        summary.addNum(num)
        for interval in summary.getIntervals():
            print("%d  %d" % (interval.start, interval.end))
        num = int(input())
