def solution(progresses, speeds):

    answer = []
    
    while True:
        
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
        n = 0
        while progresses and progresses[0]>=100:
            progresses.pop(0)
            speeds.pop(0)
            n+=1
        if n!=0:answer.append(n)
        if not progresses: break

    return answer


if __name__=="__main__":
    print(solution([95, 90, 99, 99, 80, 99],[1, 1, 1, 1, 1, 1]))