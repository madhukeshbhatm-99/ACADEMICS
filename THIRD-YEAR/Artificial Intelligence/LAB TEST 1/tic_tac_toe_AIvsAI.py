import random

board = [" "] * 9
winningPosition = [ [0,4,8] , [2,4,6] , [0,3,6], [1,4,7] , [0,1,2] , [3,4,5] , [6,7,8] , [2,5,8] ]

def boardDisplay():
    print("")
    print(board[0],end="")
    print(" | ",end="")
    print(board[1],end="")
    print(" | ",end="")
    print(board[2])
    print("----------")
    print(board[3],end="")
    print(" | ",end="")
    print(board[4],end="")
    print(" | ",end="")
    print(board[5])
    print("----------")
    print(board[6],end="")
    print(" | ",end="")
    print(board[7],end="")
    print(" | ",end="")
    print(board[8])
    print()

def checkIfAvailable(pos): 
    if board[pos] == " ":
        return 1
    else:
        return 0

def checkWin(player):
    for x in winningPosition:
        if board[x[0]] == board[x[1]] and board[x[1]] == board[x[2]] and board[x[0]] != " ":
            print(player + " has won the game!")
            return 0
    for i in board:
        if i == " ":
            return 1
    print("The match turned out to be draw!")

def algoWin(player):
    n =- 1
    for x in winningPosition:
        if board[x[0]] == player and board[x[1]] == player and checkIfAvailable(x[2]) == 1:
            n = x[2]
            break
        elif board[x[1]] == player and board[x[2]] == player and checkIfAvailable(x[0]) == 1:
            n = x[0]
            break
        elif board[x[0]] == player and board[x[2]] == player and checkIfAvailable(x[1]) == 1:
            n = x[1]
            break
    return n

def stopPlayer(player):
    n = -1
    for x in winningPosition:
        if board[x[0]] == player and board[x[1]] == player and checkIfAvailable(x[2]) == 1:
            n = x[2]
            break
        elif board[x[1]] == player and board[x[2]] == player and checkIfAvailable(x[0]) == 1:
            n = x[0]
            break
        elif board[x[0]] == player and board[x[2]] == player and checkIfAvailable(x[1]) == 1:
            n = x[1]
            break    
    return n

def algoTryWin(player):
    n = -1
    for x in winningPosition:
        if board[x[0]] == player and checkIfAvailable(x[2]==1) and checkIfAvailable(x[1]==1):
            if checkIfAvailable(x[2]==1):
                n = x[2]
                break
            elif checkIfAvailable(x[1]==1):
                n = x[1]
                break
        elif board[x[1]]==player and checkIfAvailable(x[0]==1) and checkIfAvailable(x[2]==1):
            if checkIfAvailable(x[0]==1):
                n = x[0]
                break
            elif checkIfAvailable(x[2]==1):
                n = x[2]
                break
        elif board[x[2]]==player and checkIfAvailable(x[0]==1) and checkIfAvailable(x[1]==1):
            if checkIfAvailable(x[0]==1):
                n = x[0]
                break
            elif checkIfAvailable(x[1]==1):
                n = x[1]
                break
    return n

def randomPos():
    while True:
        n = random.randint(0,8)
        if checkIfAvailable(n) == 1:
            return n

def algoPlay(x,y):
    n = algoWin(x)
    if n == -1:
        n = stopPlayer(y)
    if n == -1:
        n = algoTryWin(x)
    if n == -1:
        n = randomPos()
    print("Computer placed at ",end="")
    print(n)
    board[n] = x

def play():
    boardDisplay()
    flag = 1
    while(flag):
        print("\nComputer 1's turn")
        algoPlay("X","O")
        boardDisplay()
        if checkWin("Computer 1") == 1:
            print("\nComputer 2's turn")
            algoPlay("O","X")
            boardDisplay()
            if checkWin("Computer 2") == 0:
                flag = 0
        else:
            flag = 0

if __name__ == "__main__":
    play()