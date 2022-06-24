from collections import defaultdict
def solution(genres, plays):
    answer = []
    sing = []
    genres_time = defaultdict(int)
    for i in range(len(genres)):
        genres_time[genres[i]] += plays[i]
    for i in range(len(genres)):
        sing.append((-genres_time[genres[i]],-plays[i],i))
    sing.sort()
    
    snum = 0;
    genre = 0;
    for i in range(len(genres)):
        if genre != sing[i][0]:
            genre = sing[i][0]
            snum = 1
            answer.append(sing[i][2])
            continue
        if snum < 2:
            snum += 1
            answer.append(sing[i][2])
    return answer