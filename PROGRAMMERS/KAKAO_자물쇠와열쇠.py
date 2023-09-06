import copy

def goTurn(beforekey):
    n = len(beforekey)
    afterkey = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            afterkey[i][j] = beforekey[n-1-j][i]
    return afterkey

            
def isTrue(newkey, lock, j ,k):
    for a in range(len(lock)):
        for b in range(len(lock)):
            if newkey[j+a][k+b] == lock[a][b]:
                return False
    return True

def solution(key, lock):
    if sum([lock[i].count(0) for i in range(len(lock))]) == 0:
        return True
    
    totallen = len(key) + (len(lock) - 1) * 2
    newkey = [[0] * totallen for i in range(totallen)]
    lenlock = len(lock)
    for i in range(lenlock,lenlock + len(key)):
        for j in range(lenlock,lenlock + len(key)):
            newkey[i][j] = key[i-lenlock][j-lenlock]
            
    for i in range(4):
        for j in range(totallen-lenlock+1):
            for k in range(totallen-lenlock+1):
                if isTrue(newkey, lock, j, k):
                    return True
        newkey = goTurn(newkey)
        
    return False