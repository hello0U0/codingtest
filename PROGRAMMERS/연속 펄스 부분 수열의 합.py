def solution(sequence):
    n = len(sequence)
    answer = 0 
    pm = [1,-1]
    dp = [[0] * n for _ in range(2)]
    dp[0][0] = dp[1][0] = sequence[0]
    
    for i in range(1,n):
        a = pm[i%2] * sequence[i]
        b = dp[0][i-1] + a
        c = dp[1][i-1] + a
        
        dp[0][i] = min(a, b, c)
        dp[1][i] = max(a, b, c)
    
    answer = max([abs(i) for i in dp[0]+dp[1]])
    return answer