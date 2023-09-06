from collections import deque
def stringToTime(s):
    return int(s[:2]) * 60 * 60 + int(s[3:5]) * 60 + int(s[6:])

def timeToString(t):
    h = t//3600
    t = t%3600
    m = t//60
    s = t%60
    return f"{h:02d}:{m:02d}:{s:02d}"
        
def solution(play_time, adv_time, logs):
    play_time = stringToTime(play_time)
    adv_time = stringToTime(adv_time)
    logs = [[stringToTime(s[:8]), stringToTime(s[9:])] for s in logs]
    
    time_count = [0] * (play_time + 1)
    for s, e in logs:
        time_count[s] += 1
        time_count[e] -= 1
    #시간 별 사람 수    
    for i in range(1,len(time_count)):
        time_count[i] += time_count[i-1]
    #해당 시간 까지의 누적 재생 수 
    for i in range(1,len(time_count)):
        time_count[i] += time_count[i-1]
    
    max_time = time_count[adv_time-1]
    min_start = 0
    for i in range(1, play_time+1-adv_time):
        now_time = time_count[i+adv_time-1] - time_count[i-1]
        if now_time > max_time:
            max_time = now_time
            min_start = i
            
    answer = timeToString(min_start)
    return answer