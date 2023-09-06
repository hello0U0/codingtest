from itertools import permutations

def makeNewWeak(n, weak):
    num_weak = len(weak)
    weak_dist = [0] * num_weak
    weak_dist[0] = weak[0] + n - weak[-1]
    for i in range(1, num_weak):
        weak_dist[i] = weak[i]-weak[i-1]
    start = weak[weak_dist.index(max(weak_dist))]
    
    for i in range(num_weak):
        weak[i] = weak[i] - start
        if weak[i] < 0: weak[i] += n
    weak.sort()
    return weak

def solution(n, weak, dist):
    answer = -1
    weak = makeNewWeak(n, weak)
    dist.reverse()
    
    for i in range(1, len(dist) + 1):
        for p in permutations(dist[:i],i):
            idx = 0
            for nowp in p:
                newidx = idx
                while(weak[newidx] - weak[idx] <= nowp):
                    newidx += 1
                    if newidx >= len(weak): return i
                idx = newidx
    
    return answer