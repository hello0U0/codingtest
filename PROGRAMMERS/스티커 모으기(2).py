def solution(sticker):
    answer = 0
    if len(sticker) <= 3:
        return max(sticker)
    
    dp1 = sticker[:-1]
    dp1[1] = max(dp1[0],dp1[1])
    for i in range(2,len(dp1)):
        dp1[i] = max(dp1[i-2]+dp1[i], dp1[i-1])
    
    dp2 = sticker[:]
    dp2[0] = 0
    for i in range(2,len(dp2)):
        dp2[i] = max(dp2[i-2]+dp2[i],dp2[i-1])
        
    answer = max(dp1[-1], dp2[-1])
    return answer