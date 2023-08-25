def checkStruc(x,y,a,result):
    if y == 0:
        return True
    if a == 0:
        if [x-1,y,1] in result:
            return True
        if [x,y-1,0] in result or [x,y,1] in result:
            return True
    else:
        if [x,y-1,0] in result or [x+1,y-1,0] in result:
            return True
        if [x-1,y,1] in result and [x+1,y,1] in result:
            return True
    return False
  
def setStruc(x,y,a,b,result):
    if b == -1:
        result.remove([x,y,a])
    else:
        result.append([x,y,a])
    return result

def solution(n, build_frame):
    answer = []
    board = [[-1] * n for i in range(n)]
    for (x,y,a,b) in build_frame:
        if b == 1:
            if checkStruc(x,y,a,answer):
                setStruc(x,y,a,b,answer)
            continue
            
        b = -1
        answer = setStruc(x,y,a,b,answer)
        for (rx,ry,ra) in answer:
            if checkStruc(rx,ry,ra,answer) == False:
                answer = setStruc(x,y,a,-b,answer)
                break
        
    answer.sort()
    return answer