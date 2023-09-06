from collections import deque

def check(s1, s2):
    return sum([1 for s1i, s2i in zip(s1,s2) if s1i != s2i]) == 1

def solution(begin, target, words):
    words = [begin] + words
    visited = [False for _ in range(len(words))]
    
    q = deque()
    q.append(0)
    while(q):
        now= q.pop()
        if words[now] == target:
            return sum(visited)
        
        visited[now] = True
        for nextnode in range(len(words)):
            if visited[nextnode] == False and check(words[now], words[nextnode]):
                q.append(nextnode)
    return 0