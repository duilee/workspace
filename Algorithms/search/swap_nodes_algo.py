class Tree:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

def buildTree(indexes):
    tree = Tree(1)
    nodes = [tree]
    for i in range(len(indexes)):
        l = indexes[i][0]
        r = indexes[i][1]
        if l != -1:
            lt = Tree(l)
            nodes[i].left = lt
            nodes.append(lt)
        if r != -1:
            rt = Tree(r)
            nodes[i].right = rt
            nodes.append(rt)
        i += 1
    return tree

def traverseIter(tree):
    res = []
    stack = []
    curr = tree
    while stack or curr:
        if curr:
            stack.append(curr)
            curr = curr.left
        elif stack:
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
    return res

def swapNodes(indexes, queries):
    # Build a tree
    tree = buildTree(indexes)
    # swap nodes
    res = []
    for q in queries:
        h = 1
        stack = [tree]
        while stack:
            nextStack = []
            for node in stack:
                if h % q == 0:
                    node.left, node.right = node.right, node.left
                if node.left:
                    nextStack.append(node.left)
                if node.right:
                    nextStack.append(node.right)
            stack = nextStack
            h += 1
        # traverse the tree
        res.append(traverseIter(tree))
    return res