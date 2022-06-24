from math import ceil
def cntPeople(mid, times):
    people = sum([mid // t for t in times])
    return people

def lowerBound(left, right, target, times):
    while(left <= right):
        mid = (left + right) // 2
        people = cntPeople(mid, times)
        if people < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def solution(n, times):
    left = min(times) * ceil(n / len(times)) 
    right = max(times) * ceil(n / len(times))
    answer = lowerBound(left, right, n, times)
    return answer