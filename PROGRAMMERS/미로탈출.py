import heapq as hq
INF = 100000

def calLocation(maps, n, m):
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                start = (i,j)
            elif maps[i][j] == 'E':
                end = (i,j)
            elif maps[i][j] == 'L':
                lever = (i,j)
    return start, end, lever

def checkCanGo(newx, newy, n, m, maps):
    if newx < 0 or newx >= n:
        return False
    if newy < 0 or newy >= m:
        return False
    if maps[newx][newy] == 'X':
        return False
    return True

def dijkstra(lever, maps, n, m):
    q = []
    hq.heappush(q, (0, lever[0], lever[1]))
    dists = [[INF] * m for _ in range(n)]
    dists[lever[0]][lever[1]] = 0
    directx = [-1,1,0,0]
    directy = [0,0,-1,1]
    
    while(q):
        dist, x, y = hq.heappop(q)
        if dists[x][y] < dist:
            continue
            
        for i in range(4):
            newx = x + directx[i]
            newy = y + directy[i]
            
            if checkCanGo(newx, newy, n, m, maps) == False:
                continue
            newdist = dists[x][y] + 1
            if dists[newx][newy] > newdist:
                dists[newx][newy] = newdist
                hq.heappush(q, (newdist, newx, newy))
    
    return dists
        
    
def solution(maps):
    answer = 0
    # start -> 레버 최단거리 (SSP) + 레버 -> 문 최단거리 (SSP) => 레버에서 각 위치 최단거리
    n, m = len(maps), len(maps[0])
    start, end, lever = calLocation(maps, n, m)
    dists = dijkstra(lever, maps, n, m)
     
    answer = dists[start[0]][start[1]] + dists[end[0]][end[1]]
    if answer > INF:
        answer = -1
    return answer