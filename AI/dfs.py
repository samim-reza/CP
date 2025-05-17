def dfs(graph, start, depth, visited, result):
    """
    Depth-first search function that explores a graph up to a specified depth.
    
    Args:
        graph: Adjacency matrix representing the graph
        start: Starting node
        depth: Maximum depth to explore
        visited: Set of visited nodes
        result: List to store the visited nodes
    
    Returns:
        List of visited nodes
    """
    if depth < 0:
        return None

    if depth == 0:
        result.append(start)
        return result

    visited.add(start)
    result.append(start)

    for neighbor in range(len(graph[start])):
        if graph[start][neighbor] == 1 and neighbor not in visited:
            dfs(graph, neighbor, depth - 1, visited, result)

    return result


def iddfs(graph, start, goal, max_depth):
    """
    Iterative deepening depth-first search function.
    Gradually increases the depth until the goal is found or max depth is reached.
    
    Args:
        graph: Adjacency matrix representing the graph
        start: Starting node
        goal: Goal node to find
        max_depth: Maximum depth to search
        
    Returns:
        List of nodes in the path if goal is found, None otherwise
    """
    for depth in range(max_depth):
        print(f"Depth: {depth}")
        visited = set()
        result = []
        print(f"At Depth {depth}: ", end="")

        dfs(graph, start, depth, visited, result)
        print(" ".join(map(str, result)))

        if goal in result:
            print(f"Goal Found at depth {depth}: {result}")
            return result

    return None


def dfs_2d():
    """
    Function that performs a depth-first search on a 2D grid to find a path 
    from a source to a goal.
    """
    # Directions for movement (down, up, right, left)
    x_move = [1, -1, 0, 0]
    y_move = [0, 0, 1, -1]
    directions = 4
    
    # Initialize the graph/maze
    graph = [
        [0, 0, 1, 0, 1],
        [0, 1, 1, 1, 1],
        [0, 1, 0, 0, 1],
        [1, 1, 0, 1, 1],
        [1, 0, 0, 0, 1]
    ]
    N = len(graph)
    
    # Source and goal positions
    source_x, source_y = 0, 2
    goal_x, goal_y = 4, 4
    
    # Global variables
    found = [False]  # Using list to make it mutable in nested function
    goal_depth = [999999]  # Using list to make it mutable in nested function
    
    def print_direction(m, x, y):
        if m == 0:
            print(f"Moving Down ({x}, {y})")
        elif m == 1:
            print(f"Moving Up ({x}, {y})")
        elif m == 2:
            print(f"Moving Right ({x}, {y})")
        else:
            print(f"Moving Left ({x}, {y})")
    
    def st_dfs(x, y, depth):
        # Mark current position as visited
        graph[x][y] = 0
        
        # Try all four directions
        for j in range(directions):
            v_x = x + x_move[j]
            v_y = y + y_move[j]
            
            # Check boundary conditions and if position is valid
            if (0 <= v_x < N) and (0 <= v_y < N) and graph[v_x][v_y] == 1:
                v_depth = depth + 1
                print_direction(j, v_x, v_y)
                
                # Check if goal is reached
                if v_x == goal_x and v_y == goal_y:
                    found[0] = True
                    goal_depth[0] = v_depth
                    return
                
                # Continue DFS with new position
                st_dfs(v_x, v_y, v_depth)
                
                # If goal found in this path, return
                if found[0]:
                    return
    
    # Start DFS from source position
    st_dfs(source_x, source_y, 0)
    
    # Print result
    if found[0]:
        print("Goal found")
        print(f"Number of moves required = {goal_depth[0]}")
    else:
        print("Goal can not be reached from starting block")


def print_path():
    """
    Function to print the path from source to goal using DFS.
    This will reinitialize the graph and find the path again.
    """
    # Re-initialize the graph to its original state
    graph = [
        [0, 0, 1, 0, 1],
        [0, 1, 1, 1, 1],
        [0, 1, 0, 0, 1],
        [1, 1, 0, 1, 1],
        [1, 0, 0, 0, 1]
    ]
    N = len(graph)
    
    # Source and goal positions
    source_x, source_y = 0, 2
    goal_x, goal_y = 4, 4
    
    # Directions for movement (down, up, right, left)
    x_move = [1, -1, 0, 0]
    y_move = [0, 0, 1, -1]
    directions = 4
    
    # Path will store the coordinates from source to goal
    path = []
    found = [False]
    
    def path_dfs(x, y, current_path, visited):
        # Add current position to the path
        current_path.append((x, y))
        
        # Check if goal reached
        if x == goal_x and y == goal_y:
            found[0] = True
            path[:] = current_path[:]  # Copy the current path
            return
        
        # Mark current position as visited
        visited[x][y] = True
        
        # Try all four directions
        for j in range(directions):
            v_x = x + x_move[j]
            v_y = y + y_move[j]
            
            # Check if position is valid, not visited, and traversable
            if (0 <= v_x < N) and (0 <= v_y < N) and not visited[v_x][v_y] and graph[v_x][v_y] == 1:
                # Continue DFS with new position
                path_dfs(v_x, v_y, current_path, visited)
                
                # If goal found in this path, return
                if found[0]:
                    return
        
        # If we get here, this position didn't lead to the goal, so backtrack
        current_path.pop()
    
    # Create a visited array
    visited = [[False for _ in range(N)] for _ in range(N)]
    
    # Start path finding from source
    path_dfs(source_x, source_y, [], visited)
    
    # Print the path if found
    if found[0]:
        print("\nPath from source to goal:")
        for i, (x, y) in enumerate(path):
            print(f"Step {i}: ({x}, {y})")
        
        # Create a visual representation of the path
        visual = [['.' for _ in range(N)] for _ in range(N)]
        
        # Mark traversable and non-traversable cells
        for i in range(N):
            for j in range(N):
                if graph[i][j] == 0:
                    visual[i][j] = '#'  # Non-traversable
        
        # Mark the path
        for x, y in path:
            if (x, y) == (source_x, source_y):
                visual[x][y] = 'S'  # Source
            elif (x, y) == (goal_x, goal_y):
                visual[x][y] = 'G'  # Goal
            else:
                visual[x][y] = '*'  # Path
        
        # Print the visual representation
        print("\nPath visualization:")
        for row in visual:
            print(' '.join(row))
    else:
        print("No path could be found from source to goal")


# Example usage
if __name__ == "__main__":
    # Example graph represented as an adjacency matrix
    graph = [
        [0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 1, 1],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]
    
    # Run IDDFS
    print("Running IDDFS:")
    iddfs(graph, 0, 3, 3)
    
    # Run 2D DFS
    print("\nRunning DFS on 2D grid:")
    dfs_2d()
    
    # Print path visualization
    print_path()