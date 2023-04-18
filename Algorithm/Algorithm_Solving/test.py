class Node:
    def __init__(self,a):
        self.S =a[0]+a[1]
        if a[0]>a[1]:
            self.M=a[0]
            self.m=a[1]
        else:
            self.M=a[1]
            self.m=a[0]





def solution(scores):

    l = [0]*len(scores)
    for i,score in enumerate(scores):
        l[i] = Node(score)
    
    for i in l:
        print(i.S,i.M,i.m)

    answer = 0
    return answer


if __name__=="__main__":
    print(solution([[2,2],[1,4],[3,2],[3,2],[2,1]]))