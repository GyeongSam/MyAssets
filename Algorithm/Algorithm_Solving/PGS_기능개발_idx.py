from collections import deque
def solution(progresses, speeds):

    answer = []
    last_prog = len(progresses)
    now_prog = 0
    day =0
    while True:
        day+=1
        n = 0
        while now_prog < last_prog and (progresses[now_prog]+speeds[now_prog]*day)>=100:
            now_prog +=1
            n+=1
        if n!=0:answer.append(n)
        if now_prog == last_prog: break
    return answer


if __name__=="__main__":
    print(solution([95, 90, 99, 99, 80, 99],[1, 1, 1, 1, 1, 1]))