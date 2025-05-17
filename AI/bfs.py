import random

def generate_grid(n, obstacle_probability=0.2):
    """Generate an N x N grid with random obstacles"""
    grid = []
    for i in range(n):
        row = []
        for j in range(n):
            # Randomly place obstacles with probability 0.2 (20%)
            if random.random() < obstacle_probability:
                row.append('#')  # # represents obstacle
            else:
                row.append('.')  # . represents empty space
        grid.append(row)
    return grid

def print_grid(grid):
    """Print the grid in a readable format"""
    for row in grid:
        print(' '.join(row))

def is_valid_position(grid, position):
    """Check if a position is valid (within grid and not an obstacle)"""
    n = len(grid)
    x, y = position
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    if grid[x][y] == '#':  # obstacle
        return False
    return True

def bfs_traversal(grid, start, goal):
    """Perform BFS traversal from start to goal on the grid"""
    n = len(grid)
    
    # Directions: up, right, down, left
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    direction_names = ["Up", "Right", "Down", "Left"]
    
    # Queue for BFS
    queue = []
    queue.append(start)
    
    # Visited positions to avoid cycles
    visited = []
    for i in range(n):
        visited_row = []
        for j in range(n):
            visited_row.append(False)
        visited.append(visited_row)
    
    visited[start[0]][start[1]] = True
    
    # Parent dictionary to track path
    parent = {}
    
    # BFS algorithm
    while queue:
        current = queue.pop(0)
        
        if current == goal:
            # Goal reached, reconstruct and return the path
            path = []
            while current != start:
                path.append(current)
                current = parent[current]
            path.append(start)
            path.reverse()
            return path
        
        # Try all four directions
        for i in range(len(directions)):
            dx, dy = directions[i]
            new_x, new_y = current[0] + dx, current[1] + dy
            new_position = (new_x, new_y)
            
            if is_valid_position(grid, new_position) and not visited[new_x][new_y]:
                queue.append(new_position)
                visited[new_x][new_y] = True
                parent[new_position] = current
    
    # If no path is found
    return None

def print_moves(path):
    """Print the moves required to follow the path"""
    if not path:
        print("No path found!")
        return
    
    for i in range(1, len(path)):
        prev_x, prev_y = path[i-1]
        curr_x, curr_y = path[i]
        
        # Determine direction
        dx = curr_x - prev_x
        dy = curr_y - prev_y
        
        if dx == 1:
            direction = "Down"
        elif dx == -1:
            direction = "Up"
        elif dy == 1:
            direction = "Right"
        elif dy == -1:
            direction = "Left"
        else:
            direction = "Unknown"
        
        print(f"Moving {direction} -> ({curr_x}, {curr_y})")

# Main program
print("BFS Traversal on 2D Plane")
print("------------------------")

# Sample input for testing
sample_n = 5
sample_start = (0, 0)
sample_goal = (4, 4)
print(f"Sample Input:")
print(f"Grid size (N): {sample_n}")
print(f"Start position: {sample_start}")
print(f"Goal position: {sample_goal}")
print()

# Take user input
try:
    n = int(input("Enter grid size (N): "))
    grid = generate_grid(n)
    
    print("\nGenerated Grid:")
    print_grid(grid)
    
    start_x = int(input("\nEnter starting X coordinate: "))
    start_y = int(input("Enter starting Y coordinate: "))
    start = (start_x, start_y)
    
    goal_x = int(input("Enter goal X coordinate: "))
    goal_y = int(input("Enter goal Y coordinate: "))
    goal = (goal_x, goal_y)
    
    # Ensure start and goal are not obstacles
    if grid[start[0]][start[1]] == '#':
        grid[start[0]][start[1]] = '.'
        print("Start position was on an obstacle. Obstacle removed.")
    
    if grid[goal[0]][goal[1]] == '#':
        grid[goal[0]][goal[1]] = '.'
        print("Goal position was on an obstacle. Obstacle removed.")
    
    print("\nUpdated Grid:")
    print_grid(grid)
    
    print("\nFinding path...")
    path = bfs_traversal(grid, start, goal)
    
    print("\nMoves Required:")
    print_moves(path)
    
except ValueError:
    print("Please enter valid integer coordinates.")
except IndexError:
    print("Coordinates are outside the grid bounds.")