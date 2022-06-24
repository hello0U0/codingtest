import re

def bruteforce(banned_id_star,ban_list,now_list,maxnum):
    idx = len(now_list)
    if idx == maxnum:
        now_list = sorted(now_list)
        if now_list not in ban_list:
            ban_list.append(now_list)
        return ban_list
    for id in banned_id_star[idx]:
        now = now_list.copy()
        if id in now:
            continue
        now.append(id)
        ban_list = bruteforce(banned_id_star,ban_list,now,maxnum)
    return ban_list

def solution(user_id, banned_id):
    banned_id_star = [ list() for i in range(len(banned_id))]
    bannum = len(banned_id)
    
    for i in range(bannum):
        banned_id[i] = re.sub('\*','.',banned_id[i])
        
    for id_idx in range(len(user_id)):
        user = user_id[id_idx]
        for ban_idx in range(bannum):
            ban = banned_id[ban_idx]
            if (len(user) == len(ban)) and re.match(ban,user):
                banned_id_star[ban_idx].append(id_idx)
    
    ban_list = []
    nowlist = []
    maxnum = len(banned_id)
    ban_list = bruteforce(banned_id_star,ban_list,nowlist,maxnum)

    return len(ban_list)