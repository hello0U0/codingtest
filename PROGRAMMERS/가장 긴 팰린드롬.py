def checkPalin(s):
    end = len(s) - 1
    for i in range(len(s)//2):
        if s[i] != s[end - i]:
            return False
    return True

def solution(s):
    for length in range(len(s),1,-1):
        for i in range(len(s) - length + 1):
            if checkPalin(s[i:i+length]) == True:
                return length
    return 1