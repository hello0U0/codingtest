from collections import deque

def checkTwoWord(word1, word2):
    diff = 0
    for w1, w2 in zip(word1,word2):
        if w1 != w2:
            diff += 1
    if diff == 1:
        return True
    return False

def bfs(bfs_q, isvalid, target_idx, words):
    now_idx = bfs_q.popleft()
    # 목적 단어에 도달하면 끝
    if now_idx == target_idx:
        
        return isvalid[now_idx]
    
    for i in range(len(isvalid)):
        if isvalid[i] >= 0:
            continue
        #다음 단어로 가능하면 go
        if checkTwoWord(words[now_idx], words[i]) == True:
            isvalid[i] = isvalid[now_idx] + 1
            bfs_q.append(i)
            print(words[now_idx], isvalid, words[i])
    return 0

def solution(begin, target, words):
    answer = 0
    if not target in words:
        return 0
    
    words.append(begin)
    isvalid = [-1] * len(words)
    isvalid[-1] = 0
    
    now_idx = len(words) - 1
    target_idx = words.index(target)
    
    bfs_q = deque()
    bfs_q.append(now_idx)
    
    while(bfs_q and answer == 0):
        answer = bfs(bfs_q, isvalid, target_idx, words)
    
    return answer