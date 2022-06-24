from collections import defaultdict
def solution(gems):
    kind_gems = len(set(gems))
    endpoint = len(gems)
    gems_cnt = defaultdict(int)
    answer = [1,endpoint]
    
    sidx = 0
    eidx = 0
    gems_cnt[gems[sidx]] = 1
    count = 1
    
    while(sidx <= eidx and eidx < endpoint):
        if(count == kind_gems):
            if eidx - sidx < answer[1] - answer[0]:
                answer[0] = sidx + 1
                answer[1] = eidx + 1
            gems_cnt[gems[sidx]] -= 1
            if gems_cnt[gems[sidx]] == 0:
                count -= 1
            sidx += 1
            continue
            
        if eidx == endpoint - 1:
            break
            
        if count < kind_gems:
            eidx += 1
            if gems_cnt[gems[eidx]] == 0:
                count += 1
            gems_cnt[gems[eidx]] += 1
    return answer