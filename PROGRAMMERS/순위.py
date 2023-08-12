def floydWarshall(g):
    n = len(g)
    for i in range(1,n):
        for s in range(1,n):
            for e in range(1,n):
                if g[s][i] == 1 and g[i][e] == 1:
                    g[s][e] = 1
                    g[e][s] = -1
                elif g[s][i] == -1 and g[i][e] == -1:
                    g[s][e] = -1
                    g[e][s] = 1
    return

def solution(n, results):
    answer = 0 
    g = [[0 if i!=j else 1 for j in range(n+1)] for i in range(n+1)]
    
    for w, l in results:
        g[w][l] = 1;
        g[l][w] = -1;
        
    floydWarshall(g)
    
    answer = sum([True if r.count(0) == 1 else False  for r in g])
    return answer