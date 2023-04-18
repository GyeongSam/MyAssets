D=[(0,1),(0,-1),(1,0),(-1,0)]

def solution(maps):
    
    answer=1<<32
    n,m = len(maps),len(maps[0])
    N,M = n-1,m-1
    visit = [[0]*m for _ in '_'*n]
    Q = [(0,0,0)]
    s , e = -1, 0

    while(s<e):
        a=Q[s]
        s+=1
        visit[a[0]][a[1]]=1
        print(a)
        for di,dj in D:
            b = a[0]+di, a[1]+dj, a[2]+1
            if b[0]<0 or b[0]>=n or b[1]<0 or b[1]>=m or not maps[b[0]][b[1]] or visit[b[0]][b[1]] or b[2]>answer: continue
            if b[0]==N and b[1]==M:answer=b[2]
            stack.append(b)

    if answer==1<<32:answer=-1
    return answer


print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))