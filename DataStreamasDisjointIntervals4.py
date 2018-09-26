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
        def addNum(root, val):
            if not root:
                root = self.BSTNode(Interval(val, val))
            elif val > root.interval.end + 1:
                root.right = addNum(root.right, val)
            elif val < root.interval.start - 1:
                root.left = addNum(root.left, val)
            else:
                if val == root.interval.start - 1:
                    node = root.left
                    temp = None
                    while node and node.right:
                        temp = node
                        node = node.right
                    if node and node.interval.end == val - 1:
                        if node == root.left:
                            root.left = node.left
                        else:
                            temp.right = None
                        root.interval.start = node.interval.start
                    else:
                        root.interval.start -= 1
                if val == root.interval.end + 1:
                    node = root.right
                    temp = None
                    while node and node.left:
                        temp = node
                        node = node.left
                    if node and node.interval.start == val + 1:
                        if node == root.right:
                            root.right = node.right
                        else:
                            temp.left = None
                        root.interval.end = node.interval.end
                    else:
                        root.interval.end += 1
            return root

        self.root = addNum(self.root, val)

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
