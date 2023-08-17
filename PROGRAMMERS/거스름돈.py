def solution(n, money):
    m = len(money)
    money.sort()
    # money 1개 + 나머지 돈을 채울 경우의 수
    dp = [[0] * m for _ in range(n+1)]
    # n원을 만들 경우의 수
    dpsum = [0] * (n+1)
    # 자기자신 돈 하나로 만들 경우
    for idx, mon in enumerate(money):
        dp[mon][idx] += 1
        dpsum[mon] += 1
        
    for i in range(1,n+1):
        for midx in range(m):
            if i <= money[midx]:
                continue
            dp[i][midx] += dpsum[i-money[midx]] % 1000000007
            dpsum[i] += dp[i][midx] % 1000000007
            # 중복 제거
            dpsum[i-money[midx]] -= dp[i-money[midx]][midx]
    
    return dpsum[n] % 1000000007