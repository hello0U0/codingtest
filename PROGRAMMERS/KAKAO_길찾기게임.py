import sys
sys.setrecursionlimit(1500)

class Node:
    def __init__(self, id, x, y):
        self.id = id
        self.x = x
        self.y = y
        self.left = None
        self.right = None
    
    def __lt__(self, other):
        if self.y == other.y:
            return self.x < other.y
        return self.y > other.y
    
def addNode(parent,child):
    if child.x < parent.x:
        if parent.left is None:
            parent.left = child
        else:
            addNode(parent.left, child)
    else:
        if parent.right is None:
            parent.right = child
        else:
            addNode(parent.right, child)

def order(answer, node):
    if node is None:
        return
    answer[0].append(node.id)
    order(answer, node.left)
    order(answer, node.right)
    answer[1].append(node.id)
    return answer
    
    
def solution(nodeinfo):
    n = len(nodeinfo)
    nodes = []
    for i, (x,y) in enumerate(nodeinfo):
        nodes.append(Node(i+1,x,y))
    nodes.sort()
    root = nodes[0]
    for i in range(1,n):
        addNode(root,nodes[i])
    answer = [[],[]]
    order(answer,root)
    
    return answer
