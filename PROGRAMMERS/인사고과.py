def solution(scores):
    target= (scores[0][0],scores[0][1], scores[0][0]+scores[0][1])
    scores.sort(key=lambda x: (-x[0],x[1]))
    
    answer = 0 
    maxcoll = 0
    for s in scores:
        if target[0] < s[0] and target[1] < s[1]:
            return -1
        if maxcoll <= s[1]:
            if target[2] < s[0] + s[1]:
                answer += 1
            maxcoll = s[1]
    return answer + 1