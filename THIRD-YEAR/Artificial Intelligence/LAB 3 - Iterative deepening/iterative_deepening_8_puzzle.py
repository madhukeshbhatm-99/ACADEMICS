import copy,math

visited = []

def printBoard(board):
    for row in board:
        print(row)

def printSol(route):
    print("Solution: ")
    for step, state in enumerate(route):
        print("Move: ", step)
        printBoard(state)

def index(myList, v):
    for i, x in enumerate(myList):
        if v in x:
            return (i, x.index(v))

def gen(temp,dir,b):
    t = copy.deepcopy(temp)
    if dir == 'u':
        t[b[0]][b[1]], t[b[0] - 1][b[1]] = t[b[0] - 1][b[1]], t[b[0]][b[1]]
    elif dir == 'd':
        t[b[0]][b[1]], t[b[0] + 1][b[1]] = t[b[0] + 1][b[1]], t[b[0]][b[1]]
    elif dir == 'l':
        t[b[0]][b[1]], t[b[0]][b[1] - 1] = t[b[0]][b[1] - 1], t[b[0]][b[1]]
    elif dir == 'r':
        t[b[0]][b[1]], t[b[0]][b[1] + 1] = t[b[0]][b[1] + 1], t[b[0]][b[1]]
    return t

def possible_moves(temp,visited):
    possible_mvs = []
    b = index(temp,0)
    direction = []
    if b[0] < 2 :
        direction.append('d')
    if b[0] > 0 :
        direction.append('u')
    if b[1] < 2 :
        direction.append('r')
    if b[1] > 0 :
        direction.append('l')
    for i in direction:
        move = gen(temp,i,b)
        if move not in visited:
            possible_mvs.append(move)
    return possible_mvs

def dfs(curr, goal, visited, depth):
    if curr == goal:
        return True
    if depth <= 0:
        return False
    visited = visited + [curr]
    actions = possible_moves(curr,visited)
    for action in actions:
        if action not in visited:
            print_matrix(action)
            flag = dfs(action, goal, visited , depth-1)
            if flag == True:
                return True

def iddfs(curr, goal):
    depth = 1
    while True:
        print()
        print("Depth : " + str(depth))
        print()
        print_matrix(curr)
        if dfs(curr, goal, visited, depth) is True:
            return depth
        else:
            depth += 1

def print_matrix(mat):
    for i in mat:
        print(i)
    print()

if __name__ == '__main__':
    print()
    print("**8 PUZZLE using Iterative Deepening Depth First Search (IDDFS)**")
    print()
    goal = []
    src = []
    print("Enter the source state : ")
    for i in range(3):
        a = list(map(int, input().split()))
        src.append(a)
    print("Enter the goal state : ")
    for i in range(3):
        a = list(map(int, input().split()))
        goal.append(a)
    print()
    print("SOURCE STATE : ")
    print_matrix(src)
    print("GOAL STATE")
    print_matrix(goal)
    depth = iddfs(src,goal)
    if depth:
        print("The Puzzle is solved at depth " + str(depth))
