from collections import deque
def solution(s):
    answer = True
    d = deque()
    
    for si in s:
        if si == '(':
            d.append(si)
            continue
        if len(d) > 0 and d[-1] == '(':
            d.pop()
        else:
            return False
    if len(d) > 0:
        return False
    return True