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
        result = []
        path = []
        
        stack = []
        cur = root
        pre = None
        
        SUM=0
        
        while cur or len(stack)>0:
            while cur:
                stack.append(cur)
                SUM += cur.val
                path.append(cur.val)
                cur = cur.left
            cur = stack[-1]
            if cur.right and cur.right!=pre:
                cur = cur.right
                continue
            if cur.left==None and cur.right==None and SUM==sum:
                result.append(path+[])
            pre = cur
            path.pop()
            SUM -= cur.val;
            stack.pop()
            cur = None
        
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
