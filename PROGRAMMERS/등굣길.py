def solution(m, n, puddles):
    answer = 0
    road = [[0 for i in range(n+1)] for i in range(m+1)] 
    road[1][1] = 1
    for p in puddles:
        road[p[0]][p[1]] = -1
    
    for i in range(1,m+1):
        for j in range(1,n+1):
            if (i==1 and j==1) or road[i][j] == -1:
                continue
            road[i][j] = (max(road[i-1][j],0) + max(road[i][j-1],0)) % 1000000007
            
    answer = road[m][n]
    return answer