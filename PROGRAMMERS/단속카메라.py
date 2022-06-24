def solution(routes):
    answer = 0
    routes = sorted(routes, key=lambda x: x[1])
    camera = routes[0][0] - 1
    for route in routes:
        if route[0] <= camera and camera <= route[1]:
            continue
        camera = route[1]
        answer += 1
    return answer