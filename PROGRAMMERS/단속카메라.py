def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    lastcamera = routes[0][0] - 1
    
    for rs, re in routes:
        if lastcamera < rs:
            lastcamera = re
            answer += 1
    return answer