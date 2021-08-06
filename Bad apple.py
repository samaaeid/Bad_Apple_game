import random

N= 3
counter = 0
a, b = -1, -1
grid = [['+' for x in range(N)] for y in range(N)]


# This function prints the grid of Gomoku as the game progresses
def print_grid():
    print('--' + '---' * N + '--')
    for i in range(N):
        print(end='|  ')
        for j in range(N):
            print(grid[i][j], end='  ')
        print(end='|')
        print()
    print('--' + '---' * N + '--')


# This function checks if the game has a win state or not
def check_win():
    c = 0
    for i in range(N):
        for j in range(N):
            if grid[i][j] == '*':
                c+=1

    if c == 1:
        return True
    else:
        return False

# This function checks if the game has a tie state or not for the given mark
def check_lose(i,j,a):
    if a == 0 or a == 1 or a == 2:
        grid[i][j]='X'
        return True
    else :
       return False



# This function generates pac man
def generate_apple():
    global a
    a = random.randint(0, N**2)
    return a


def check_valid_index(i,j):
    return  grid[i][j] == '*'

# This function checks if given position is valid or not
def check_valid_position(i,j):

    valid = 0 <=i<N  and   0 <= j <N
    return valid

def set_cell( i,  j,  a):
    global counter
    if a%2:
        grid[i][j]='1'
        counter+=1
    elif a%2==0 :
        grid[i][j]='0'

# This function clears the game structures
def grid_clear():
    global grid
    grid = [['*' for x in range(N)] for y in range(N)]
    global counter
    counter = 0


# This function reads a valid position input
def read_input():
    i ,j =  map(int, input('Enter the row index and column index: ').split())
    while not check_valid_position(i, j) or not check_valid_index(i,j):
        i, j = map(int, input('Enter a valid row index and a valid column index: ').split())
    return i,j


# MAIN FUNCTION
def play_game():
    print("Bad apples Game!")
    print("Welcome...")
    print("============================")
    while True:
        # Prints the grid
        print_grid()
        print("Your score is : ",counter)
        i,j = read_input()
        a = generate_apple()
        # Check if the grid has a tie state
        if check_lose(i,j,a):
            # Prints the grid
            print_grid()
            # Announcement of the final statement
            print("GAME OVER!")
            break
        else:
            set_cell(i,j,a)

        # Check if the state of the grid has a win state
        if check_win():
            # Prints the grid
            print_grid()
            # Announcement of the final statement
            print("Congrats, you won!\n")
            break


while True:
    grid_clear()
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
