import heapq as hp

def remove_invalid_heap(pri_q, is_valid):
    while pri_q and is_valid[pri_q[0][1]] == False:
        hp.heappop(pri_q)
    return pri_q
    

def solution(operations):
    answer = [0,0]
    
    max_pri_q = []  #최대값 큐
    min_pri_q = []  #최소값 큐
    is_valid = []   #값이 존재하는가(빼면 False)
    idx = 0         
    
    for oper in operations:
        # I 숫자일 경우 숫자 삽입
        cmd, num = oper.split()
        if cmd == 'I':
            hp.heappush(max_pri_q,(-int(num), idx))
            hp.heappush(min_pri_q,(int(num), idx))
            is_valid.append(True)
            idx += 1
            continue
            
        # D 1 일 경우 최댓값 삭제
        if num == '1':
            max_pri_q = remove_invalid_heap(max_pri_q, is_valid) #없는 값 제거
            if max_pri_q:
                max_num, max_idx = hp.heappop(max_pri_q)
                is_valid[max_idx] = False
        # D -1 일 경우 최솟값 삭제
        else:
            min_pri_q = remove_invalid_heap(min_pri_q, is_valid) #없는 값 제거
            if min_pri_q:
                min_num, min_idx = hp.heappop(min_pri_q)
                is_valid[min_idx] = False 
                
    max_pri_q = remove_invalid_heap(max_pri_q, is_valid)
    min_pri_q = remove_invalid_heap(min_pri_q, is_valid)
    if max_pri_q: 
        answer[0] = -max_pri_q[0][0] 
    if min_pri_q :
        answer[1] = min_pri_q[0][0] 
    return answer