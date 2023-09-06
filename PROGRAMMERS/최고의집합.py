def solution(n, s):
    answer = []
    if s//n == 0:
        return [-1]
    
    num = s//n
    cnt = s%n
    answer = [num for i in range(n-cnt)] + [num + 1 for  i in range(cnt)]
    return answer