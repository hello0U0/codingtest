INF = 20000001
def floydWarshall(dist, n):
    for mid in range(1, n+1):
        for start in range (1, n+1):
            for end in range(1, n+1):
                nowfare = dist[start][mid] + dist[mid][end]
                if nowfare < dist[start][end]:
                    dist[start][end] = min(nowfare, dist[start][end])
    return dist

def solution(n, s, a, b, fares):
    answer = 0
    
    dist = [[INF] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n+1):
        dist[i][i] = 0
    
    for start, end, fare in fares:
        dist[start][end] = fare
        dist[end][start] = fare
        
    dist = floydWarshall(dist, n)
    
    minfare = dist[s][a] + dist[s][b]
    for i in range(1, n+1):
        nowfare = dist[s][i] + dist[i][a] + dist[i][b]
        minfare = min(nowfare, minfare)
    
    answer = minfare
    return answer 