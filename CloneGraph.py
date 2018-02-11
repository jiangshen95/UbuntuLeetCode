class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
        
class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node == None:
            return None
        dic = {}
        copy = UndirectedGraphNode(node.label)
        dic[node] = copy
        stack = []
        stack.append(node)
        while stack:
            cur = stack.pop()
            for neighbor in cur.neighbors:
                if neighbor not in dic:
                    newnode = UndirectedGraphNode(neighbor.label)
                    dic[neighbor] = newnode
                    stack.append(neighbor)
                dic[cur].neighbors.append(dic[neighbor])
        return copy
        
