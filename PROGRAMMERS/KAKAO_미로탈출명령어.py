# 사전순 : dlru
def solution(n, m, x, y, r, c, k):
    answer = ''
    times = {'d': 0, 'l':0, 'r':0, 'u':0}
    dist = abs(r - x) + abs(c - y)
    k -= dist
    if k % 2 != 0 or k < 0:
        return "impossible"
    # 최단 방향 체크
    if x > r:
        times['u'] += x - r
    else:
        times['d'] += r - x
    if c > y:
        times['r'] += c - y
    else:
        times['l'] += y - c
    
    #d 움직이고 더 갈 수 있으면 가기
    answer += 'd' * times['d']
    x += times['d']
    move = min(k // 2, n-x)
    answer += 'd' * move
    times['u'] += move
    k -= 2 * move
    
    # l 가고 더 갈 수 있으면 가기
    answer += 'l' * times['l']
    y -= times['l']
    move = min(k//2, y-1)
    answer += 'l' * move
    times['r'] += move
    k -= 2 * move
    
    # 남은 만큼 rl 반복
    if k > 0:
        answer += 'rl' * (k//2)
    
    # r,u 가기
    answer += 'r' * times['r']
    answer += 'u' * times['u']
       
    return answer