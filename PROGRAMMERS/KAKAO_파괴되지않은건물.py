def accumSum(bb):
    for i in range(1,len(bb)):
        for j in range(len(bb[0])):
            bb[i][j] += bb[i-1][j]
            
    for i in range(len(bb)):
        for j in range(1, len(bb[0])):
            bb[i][j] += bb[i][j-1]
    
    bb = [b[:-1] for b in bb[:-1]]
    return bb

def solution(board, skill):
    plus = [[0] * (len(board[0])+1) for _ in range(len(board)+1)]
    for types, r1, c1, r2, c2, degree in skill:
        types = 1 if types == 2 else -1
        plus[r1][c1] += types * degree
        plus[r1][c2+1] -= types * degree
        plus[r2+1][c1] -= types * degree
        plus[r2+1][c2+1] += types * degree
        
    plus = accumSum(plus)
    board = [[b[i]+p[i] for i in range(len(b))] for b,p in zip(board, plus)]
    board = [[1 for d in b if d > 0] for b in board]
    answer = sum([sum(b) for b in board])
    return answer