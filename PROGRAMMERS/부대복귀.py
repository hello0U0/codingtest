from collections import deque
def solution(n, roads, sources, destination):
    g = [[] for _ in range(n+1)]
    for road in roads:
        g[road[0]].append(road[1])
        g[road[1]].append(road[0])
    destDist = [-1] * (n+1)
    q = deque()
    
    q.append((destination,0))
    while(q):
        now, dist = q.popleft()
        if destDist[now] != -1:
            continue
        destDist[now] = dist
        for next in g[now]:
            q.append((next, dist+1))
    
    answer = [destDist[s] for s in sources]
    return answer