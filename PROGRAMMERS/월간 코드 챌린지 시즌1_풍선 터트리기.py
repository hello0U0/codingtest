def solution(a):
    answer = 0
    n = len(a)
    prob_remain = [False] * n
    minidx = a.index(min(a))
    prob_remain[minidx] = True
    print(minidx)
    
    nowmin = 10 ** 9 + 1
    for i in range(minidx):
        if nowmin > a[i]:
            prob_remain[i] = True
            nowmin = a[i]
            
    nowmin = 10 ** 9 + 1
    for i in range(n - 1, minidx, -1):
        if nowmin > a[i]:
            prob_remain[i] = True
            nowmin = a[i]
            
    answer = sum(prob_remain)    
    return answer