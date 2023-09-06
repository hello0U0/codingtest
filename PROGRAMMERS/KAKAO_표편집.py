class Node:
    def __init__(self,id,up=None,down=None):
        self.id = id
        self.up = up
        self.down = down
        
    def changeup(self,node):
        self.up = node
        
    def changedown(self,node):
        self.down = node

def delete(node):
    u = node.up
    d = node.down
    if u:
        u.changedown(d)
    if d:
        d.changeup(u)
        return d.id
    return u.id

def undo(node):
    u = node.up
    d = node.down
    if u:
        u.changedown(node)
    if d:
        d.changeup(node)

def goUp(node, k):
    for i in range(k):
        node = node.up
    return node.id

def goDown(node, k):
    for i in range(k):
        node = node.down
    return node.id

def makeNodes(n):
    nodes = [Node(i) for i in range(n)]
    for i in range(n):
        if i > 0:
            nodes[i].changeup(nodes[i-1])
        if i < n - 1:
            nodes[i].changedown(nodes[i+1])
    return nodes

def solution(n, k, cmd):
    answer = ''
    nodes = makeNodes(n)        
    dellist = []
    state = [True] * n
    for c in cmd:
        if c == "C":
            dellist.append(k)
            state[k] = False
            k = delete(nodes[k])
        elif c == "Z":
            undo(nodes[dellist[-1]])
            state[dellist[-1]] =True
            dellist.pop()
        elif c[0] == "U":
            k = goUp(nodes[k],int(c[2:]))
        else:
            k = goDown(nodes[k],int(c[2:]))
    answer = ['O' if s else 'X' for s in state]
    answer = ''.join(answer)
    return answer