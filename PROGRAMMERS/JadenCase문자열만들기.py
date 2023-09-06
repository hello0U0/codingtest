def check(word):
    if word == '':
        return word
    else : 
        return word[0].upper() + word[1:].lower()

def solution(s):
    answer = ' '.join(map(check, s.split(' ')))
    return answer