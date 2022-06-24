import re
from itertools import product

def solution(user_id, banned_id):
    answer = set()
    banned_id_star = [ list() for i in range(len(banned_id))]
    bannum = len(banned_id)
    
    for i in range(bannum):
        banned_id[i] = re.sub('\*','.',banned_id[i])
        
    for id_idx in range(len(user_id)):
        user = user_id[id_idx]
        for ban_idx in range(bannum):
            ban = banned_id[ban_idx]
            if (len(user) == len(ban)) and re.match(ban,user):
                banned_id_star[ban_idx].append(user)
                
    ban_list = list(product(*banned_id_star))
    for ban in ban_list:
        if len(set(ban)) == bannum:
            answer.add("".join(sorted(ban)))
            
    return len(answer)