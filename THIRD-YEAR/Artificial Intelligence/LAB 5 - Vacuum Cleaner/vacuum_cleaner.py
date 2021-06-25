def cleanFloor(floor):
    row, col = len(floor), len(floor[0])
    for i in range(row):
        if i % 2 == 0:
            for j in range(col):
                if floor[i][j] == 1:
                    printFloor(floor, i, j)
                    print("This cell is dirty")
                    floor[i][j] = 0
                    print("After cleaning, ")
                    printFloor(floor, i, j)
                    print("Moving to next cell")
                    print()
                else:
                    printFloor(floor, i, j)
                    print("This cell is clean,")
                    print("Moving to next cell")
                    print()
        else:
            for j in range(col-1, -1, -1):
                if floor[i][j] == 1:
                    printFloor(floor, i, j)
                    print("This cell is dirty")
                    floor[i][j] = 0
                    print("After cleaning, ")
                    printFloor(floor, i, j)
                    print("Moving to next cell")
                    print()
                else:
                    printFloor(floor, i, j)
                    print("This cell is clean, ")
                    print("Moving to next cell")
                    print()

def printFloor(floor, row, col):
    print("The floor matrix is: ")
    for r in range(len(floor)):
        for c in range(len(floor[r])):
            if r == row and c == col:
                print(f" [{floor[r][c]}] ", end = '')
            else:
                print(f"  {floor[r][c]}  ", end = '')
        print()

def main():
    floor = []
    m = int(input("Enter the number of Rows: "))
    n = int(input("Enter the number of Columns: "))
    print("Enter the Floor matrix, each cell representing Clean (0) or Dirty(1)")
    for i in range(m):
        f = list(map(int, input().split(" ")))
        floor.append(f)
    print()
    cleanFloor(floor)
    print()
    print("Now, the floor is cleaned!")
    printFloor(floor, m, n)

main()