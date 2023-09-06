import heapq as hq
def solution(stones, k):
    stop = [(-stones[i], i) for i in range(len(stones[:k]))]
    hq.heapify(stop)
    answer = -stop[0][0]
    
    for i in range(k, len(stones)):
        while(stop and stop[0][1] <= i-k):
            hq.heappop(stop)
        hq.heappush(stop, (-stones[i],i))
    
        if -stop[0][0] < answer:
            answer = -stop[0][0]
            
    return answer