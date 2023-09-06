import heapq as hp
def solution(n, works):
    answer = 0
    works = [-i for i in works]
    hp.heapify(works)
    while n > 0:
        max_num = hp.heappop(works)
        if max_num == 0:
            return 0
        hp.heappush(works,  max_num + 1)
        n -= 1
    print(works)
    answer = sum([i**2 for i in works])
    
    return answer