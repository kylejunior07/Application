import random

def create_numbrix_puzzle(size, difficulty):
    # Initialize the grid
    grid = [[0 for _ in range(size)] for _ in range(size)]

    # Check if the move is within the grid and the cell is not filled
    def is_valid(x, y):
        return 0 <= x < size and 0 <= y < size and grid[x][y] == 0

    # DFS to fill the grid
    def dfs(x, y, num):
        if num > size * size:
            return True  # Puzzle is fully generated
        if not is_valid(x, y):
            return False  # Invalid move

        grid[x][y] = num
        # Try moving in each direction
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            if dfs(x + dx, y + dy, num + 1):
                return True

        grid[x][y] = 0  # Backtrack if no direction is valid
        return False

    # Start DFS from the top-left corner
    dfs(0, 0, 1)

    # Remove numbers to create the puzzle
    for i in range(size):
        for j in range(size):
            if random.random() < difficulty:
                grid[i][j] = 0

    return grid

# Example usage
size = 6
difficulty = 0.4
puzzle = create_numbrix_puzzle(size, difficulty)

# Print the puzzle
for row in puzzle:
    print(' '.join(str(num).rjust(2) for num in row))
