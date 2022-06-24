def solution(s):
    answer = [0,0]
    while(s != "1"):
        zero = s.count('0')
        answer[1] += zero
        s = format(len(s) - zero, 'b')
        answer[0] += 1
    
    return answer