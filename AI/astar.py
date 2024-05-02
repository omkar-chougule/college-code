import heapq

def heuristic(state, goal):
    misplaced = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != goal[i][j]:
                misplaced += 1
    return misplaced

def a_star_search(start, goal):
    open_list = []
    closed_list = set()
    heapq.heappush(open_list, (heuristic(start, goal), start, 0, []))

    while open_list:
        _, current, cost, path = heapq.heappop(open_list)
        if current == goal:
            return path
        closed_list.add(tuple(map(tuple, current)))

        zero_i, zero_j = next((i, j) for i, row in enumerate(current) for j, val in enumerate(row) if val == 0)

        for move_i, move_j, operation in ((0, 1, 'right'), (0, -1, 'left'), (1, 0, 'down'), (-1, 0, 'up')):
            new_i, new_j = zero_i + move_i, zero_j + move_j
            if 0 <= new_i < 3 and 0 <= new_j < 3:
                new_state = [row[:] for row in current]
                new_state[zero_i][zero_j], new_state[new_i][new_j] = new_state[new_i][new_j], new_state[zero_i][zero_j]
                if tuple(map(tuple, new_state)) not in closed_list:
                    new_cost = cost + 1
                    heapq.heappush(open_list, (new_cost + heuristic(new_state, goal), new_state, new_cost, path + [(operation, new_state)]))
    return None

#INPUT FROM USER
def take_input():
    print("Enter the initial state of the 8-puzzle (3x3 grid, use 0 to represent the blank space):")
    initial_state = []
    for i in range(3):
        row = list(map(int, input().split()))
        initial_state.append(row)
    return initial_state

def take_goal():
    print("Enter the goal state of the 8-puzzle (3x3 grid, use 0 to represent the blank space):")
    goal_state = []
    for i in range(3):
        row = list(map(int, input().split()))
        goal_state.append(row)
    return goal_state

def print_puzzle_path(path):
    for step, (operation, state) in enumerate(path):
        print(f"Step {step + 1}: Perform {operation}")
        for row in state:
            print(row)
        print(f"Heuristic Value: {heuristic(state, goal_state)}")
        print()


start_state = take_input()
goal_state = take_goal()
path = a_star_search(start_state, goal_state)
if path:
    print("Solution path:")
    print_puzzle_path(path)
else:
    print("No solution found")