import math
def solution(n, stations, w):
    answer = 0

    elect = []
    for s in stations:
        elect.append((max(0,s-w),min(n,s+w)))
    print(elect)
    elect.append((n+1,n+1))
    elect.sort(key = (lambda x: x[1]))
    
    one_s_range = 2 * w + 1 
    endpoint = 0
    for e in elect:
        if endpoint < e[0]:
            #print("endpoint:",endpoint," e[0]:",e[0])
            answer += math.ceil((e[0] - endpoint - 1) / one_s_range)
            #print(answer)
        endpoint = e[1]
    return answer