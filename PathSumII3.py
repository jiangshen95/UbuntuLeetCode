class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if root==None:
            return []
        result = []
        queue = [(root, root.val, [root.val])]
        
        while queue:
            cur, val, ls = queue.pop(0);
            if cur.left==None and cur.right==None and val==sum:
                result.append(ls)
            if cur.left:
                queue.append((cur.left, val+cur.left.val, ls+[cur.left.val]))
            if cur.right:
                queue.append((cur.right, val+cur.right.val, ls+[cur.right.val]))
        
        return result
        
if __name__=='__main__':
    root=TreeNode(5);
    a=TreeNode(4);
    b=TreeNode(8);
    c=TreeNode(11);
    d=TreeNode(13);
    e=TreeNode(4);
    f=TreeNode(7);
    g=TreeNode(2);
    h=TreeNode(1);
    k=TreeNode(5)
    
    root.left=a;
    root.right=b;
    a.left=c;
    b.left=d;
    b.right=e;
    c.left=f;
    c.right=g;
    e.left=k;
    e.right=h;
    
    sum = int(raw_input())
    
    solution = Solution()
    print(solution.pathSum(root, sum))
