def solution(info, edges):
    answer = 0
    n = len(info)
    visited = [False] * n
    
    def dfs(sheep, wolf,answer):
        if wolf >= sheep or sum(visited) == n:
            answer = max(answer,sheep)
            return answer
        
        for s, e in edges:
            if not (visited[s] == True and visited[e] == False):
                continue
            visited[e] = True
            if info[e] == 1:
                answer = dfs(sheep, wolf+1,answer)
            else: 
                answer = dfs(sheep+1, wolf,answer)
            visited[e] = False
        
        return answer

    visited[0] = True
    answer = dfs(1,0,0)
    return answer