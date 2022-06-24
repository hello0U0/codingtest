def solution(A, B):
    answer = 0
    A.sort()
    B.sort()
    aidx = 0
    for i in range(len(B)):
        if A[aidx] < B[i]:
            answer += 1
            aidx += 1 
    return answer