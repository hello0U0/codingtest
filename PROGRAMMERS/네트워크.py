def rootNode(num,node):
    if node[num] < 0:
        return num
    node[num] = rootNode(node[num],node)
    return node[num]

def connect(a, b, node):
    root_a = rootNode(a, node)
    root_b = rootNode(b, node)
    
    if root_a == root_b:
        return
    elif root_a <= root_b:
        node[root_a] -= root_b
        node[root_b] = root_a
    else:
        node[root_b] -= root_a
        node[root_a] = root_b
    return

def solution(n, computers):
    answer = 0
    node = [-1] * n
    
    for a in range(n):
        for b in range(n):
            if computers[a][b] == 1:
                connect(a,b,node)
    answer = sum([i < 0 for i in node])
    return answer