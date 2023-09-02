def meetPoint(line1, line2):
    a1, b1, c1 = line1
    a2, b2, c2 = line2    
    if b1 != 0 and b2 != 0 and a1/b1 == a2/b2:
        return -1
    if a1 != 0 and a2 != 0 and b1/a1 == b2/a2:
        return -1
    
    xa, xb = (b1*c2 - c1*b2), (a1*b2 - b1*a2)
    ya, yb = (c1*a2 - a1*c2), (a1*b2 - b1*a2)
    if xa % xb !=0 or ya % yb != 0:
        return -1
    return (xa//xb ,ya//yb)

def solution(line):
    meet_point = []
    for i in range(len(line)):
        for j in range(i+1,len(line)):
            xy = meetPoint(line[i],line[j])
            if xy != -1:
                meet_point.append(xy)
    meet_point= list(set(meet_point))
    
    x_list, y_list  = [x for x,_ in meet_point], [y for _,y in meet_point]
    minx, maxx = min(x_list), max(x_list)
    miny, maxy = min(y_list), max(y_list)
    meet_point = [(maxy-y, x-minx) for x,y in meet_point]
    
    answer = [["."] * (maxx-minx+1) for _ in range(maxy-miny+1)]
    for (x,y) in meet_point:
        answer[x][y] = "*"
    answer = ["".join(a)for a in answer]
    return answer