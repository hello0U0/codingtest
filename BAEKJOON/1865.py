# 1865 웜홀
def bellmanFord(n, edges):
    dist = [0] * (n + 1)

    for i in range(1,n+1):
        flag = True
        for s,e,w in edges:
            nw = dist[s] + w
            if nw < dist[e]:
                dist[e] = nw
                flag = False;
                
        if flag:
            return "NO"
        if i == n:
            return "YES"
    
def main():
    tc = int(input())
    for _ in range(tc):
        n, m, w, = map(int,input().split())
        edges = []
        for _ in range(m):
            s, e, t = map(int, input().split())
            edges.append((s, e, t))
            edges.append((e, s, t))
            
        for _ in range(w):
            s, e, t = map(int, input().split())
            edges.append((s, e, -t))
            
        print(bellmanFord(n, edges))

if __name__ == '__main__':
    main()
