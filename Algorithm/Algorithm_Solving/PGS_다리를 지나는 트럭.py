from collections import deque
def solution(bridge_length, weight, truck_weights):
    time = 0

    bridge_queue = deque([0]*bridge_length)
    wait_queue = deque(truck_weights)
    bridge_total_weight = 0

    while wait_queue:
        time+=1
        bridge_total_weight-=bridge_queue.popleft()
        if bridge_total_weight + wait_queue[0] <=weight:
            bridge_total_weight+=wait_queue[0]
            bridge_queue.append(wait_queue.popleft())
        else: bridge_queue.append(0)
    return time+bridge_length

if __name__ == "__main__":
    print(solution(2,10,[7,4,5,6]))