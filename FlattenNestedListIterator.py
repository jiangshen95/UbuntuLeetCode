class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        def gen(nestedList):
            for i in nestedList:
                if i.isInteger():
                    yield i.getInteger()
                else:
                    for j in gen(i.getList()):
                        yield j
        self.gen = gen(nestedList)

    def next(self):
        """
        :rtype: int
        """
        return self.value

    def hasNext(self):
        """
        :rtype: bool
        """
        try:
            self.value = next(self.gen)
            return True
        except StopIteration:
            return False