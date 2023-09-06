def upperbound(bustime, time):
    left = 0
    right = len(bustime) - 1
    while(left <= right):
        mid = (left + right) // 2
        if bustime[mid] <= time:
            left = mid + 1
        else:
            right = mid - 1
    return left

def solution(n, t, m, timetable):
    bustime = [0] * n
    for i in range(n):
        bustime[i] = 540 + t * i
    
    timetable = [60 * int(time[:2]) + int(time[-2:]) for time in timetable] + [60 * 24]
    timetable.sort()
    
    startidx = 0 #시작번호
    leftover = 0
    people = 0
    
    for bus in bustime:
        # 현재 탄 사람 수
        nextidx = upperbound(timetable, bus)
        people = nextidx - startidx
        
        leftover = people - m
        
        if people > m:
            startidx = startidx + m
        else:
            startidx = nextidx
    
    if leftover >= 0:
        answer = timetable[startidx - 1] - 1
    else:
        answer = bustime[-1]
    answer = f'{answer // 60:02d}' + ":" + f'{answer % 60:02d}'
    
    return answer